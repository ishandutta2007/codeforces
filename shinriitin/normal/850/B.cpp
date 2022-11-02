#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

const int max_N=1e6;

int n,x,y,a[max_N+21];

long long cnt[max_N+21];

int q[max_N+21];

inline bool cmp(int x,int y){
	if(cnt[x]!=cnt[y])return cnt[x]>cnt[y];
	return x<y;	
}

inline long long solve(int tmp){
	long long res=0;
	for(int i=1;i<=n;++i)res+=std::min(1ll*x,1ll*(tmp-a[i]%tmp)%tmp*y);
	return res;
}

int main(){
	read(n),read(x),read(y);
	for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]];
	for(int i=1;i<=max_N;++i)for(int j=i+i;j<=max_N;j+=i)cnt[i]+=cnt[j];
	for(int i=2;i<=max_N;++i)q[i]=i;
	std::sort(q+2,q+1+max_N,cmp);
	long long ans=1ll<<60;
	for(int i=2;i<=200;++i)ans=std::min(ans,solve(q[i]));
	printf("%I64d\n",ans);
	return 0;	
}