#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define max_N 5005
typedef long long ll;

char s[max_N],s1[max_N],s2[max_N];

int n,m;

ll f[max_N],g[max_N],h1[max_N],h2[max_N],ans;

inline void init(char*s,ll*f,ll*h){
	f[1]=h[1]=s[1]-48;
	for(int i=2,j;i<=m;++i){
		if(s[(i-1)<<1]=='+'){
			h[i]=s[(i-1)<<1|1]-48;
			f[i]=f[i-1]+h[i];
		}
		else{
			h[i]=h[i-1]*(s[(i-1)<<1|1]-48);
			f[i]=f[i-1]-h[i-1]+h[i];
		}
	}
}

inline void solve(char*s,ll*f,ll*h1,ll*g,ll*h2){
	for(int i=1,j,k;i<m;++i)if(s[i<<1]=='*'){
		ll sum=s[i<<1|1]-48,tmp,tmp1=s[i<<1|1]-48;
		for(j=i+1;j<m;++j){
			if(s[j<<1]=='+')tmp=s[j<<1|1]-48,sum+=tmp;
			else tmp=tmp1*(s[j<<1|1]-48),sum=sum-tmp1+tmp;
			tmp1=tmp;
			if(j==m-1||s[(j+1)<<1]=='+')ans=max(ans,f[i]-h1[i]+h1[i]*sum+h2[m-j-1]);
			else ans=max(ans,f[i]-h1[i]+h1[i]*sum*h2[m-j-1]-h2[m-j-1]+g[m-j-1]);
		}
	}
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=(n+1)>>1;
	for(int i=1;i<=n;++i)s1[i]=s[n-i+1];
	init(s,f,h1),init(s1,g,h2);
	ans=f[m];
	solve(s,f,h1,g,h2),solve(s1,g,h2,f,h1);
	printf("%I64d\n",ans);
	return 0;
}