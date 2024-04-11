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
#define max_L 1000005

int n,r,a[max_N],s[max_L<<1],ans;

int main(){
	n=gint();
	for(int i=1;i<=n;++i)a[i]=gint(),s[a[i]]=a[i],r=max(r,a[i]);
	for(int i=1;i<=2*r;++i)s[i]=max(s[i],s[i-1]);
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;++i)
		for(int j=a[i];j<=r;j+=a[i])
			ans=max(ans,s[j+a[i]-1]-j);
	printf("%d\n",ans);
	return 0;
}