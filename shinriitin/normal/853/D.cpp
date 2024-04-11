#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

const int max_N=3e5;

typedef long long ll;

const ll inf=1ll<<40;

int n,p[max_N+21];

ll f[max_N+21][31];

int main(){
	read(n);
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=0;i<=n;++i)for(int j=0;j<=30;++j)f[i][j]=inf;
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0,k;j<=30;++j){
			k=j+p[i]/1000;
			if(k<=30)f[i][k]=std::min(f[i][k],f[i-1][j]+p[i]);
			k=j-p[i]/100;
			if(k>=0)f[i][k]=std::min(f[i][k],f[i-1][j]);
			if(p[i]>j*100)f[i][0]=std::min(f[i][0],f[i-1][j]+p[i]-j*100);
		}
	}
	ll ans=-1;
	for(int i=0;i<=30;++i)if(ans==-1||ans>f[n][i])ans=f[n][i];
	printf("%I64d\n",ans);
	return 0;
}