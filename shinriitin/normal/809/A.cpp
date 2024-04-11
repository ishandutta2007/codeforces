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

#define max_N 300005
#define mod 1000000007

int n,x[max_N],pw2[max_N],ans;

int main(){
	n=gint();
	pw2[0]=1;
	for(int i=1;i<=n;++i)x[i]=gint(),pw2[i]=(pw2[i-1]<<1)%mod;
	sort(x+1,x+1+n);
	for(int i=1;i<=n;++i){
		ans=(ans+1ll*pw2[i-1]*x[i]%mod)%mod;
		ans=(ans-1ll*pw2[n-i]*x[i]%mod)%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}