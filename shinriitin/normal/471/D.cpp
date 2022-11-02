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

#define max_N 200005

int n,m,a[max_N],b[max_N],f[max_N];

int A[max_N],B[max_N],ans;

int main(){
	n=gint(),m=gint();
	if(m==1)return printf("%d\n",n),0;
	for(int i=1;i<=n;++i)a[i]=gint();
	for(int i=1;i<=m;++i)b[i]=gint();
	--n,--m;
	for(int i=1;i<=n;++i)A[i]=a[i]-a[i+1];
	for(int i=1;i<=m;++i)B[i]=b[i]-b[i+1];
	for(int i=2,j;i<=m;++i){
		for(j=f[i-1];j&&B[j+1]!=B[i];j=f[j]);
		f[i]= B[j+1]==B[i]?j+1:0;
	}
	for(int i=1,j=0;i<=n;++i){
		for(;j&&B[j+1]!=A[i];j=f[j]);
		if(B[j+1]==A[i])++j;
		if(j==m)++ans,j=f[j];
	}
	return printf("%d\n",ans),0;
}