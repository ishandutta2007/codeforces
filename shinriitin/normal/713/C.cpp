#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 3005
#define Abs(x) ((x)>0?(x):-(x))

int n,a[max_N],h[max_N],tot;

typedef long long ll;

ll f[max_N][max_N];

int main(){
	n=gint();
	for(int i=1;i<=n;++i){
		a[i]=gint()-i;
		h[i]=a[i];
	}
	sort(h+1,h+1+n);
	tot=unique(h+1,h+1+n)-h-1;
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=tot;++j){
			f[i][j]=f[i-1][j]+Abs(h[j]-a[i]);
			if(j>1)f[i][j]=min(f[i][j],f[i][j-1]);
		}
	printf("%lld\n",f[n][tot]);
	return 0;
}