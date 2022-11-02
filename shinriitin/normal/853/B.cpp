#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

typedef long long ll;

const int max_N=1e5,max_K=1e6;

int n,m,k,cnt;

ll ans,tmp,f[max_N+21],pre[max_K+21],suf[max_K+21];

struct flight{int x,d,w;};

std::vector<flight>fli[2];

inline bool cmp1(const flight&a,const flight&b){
	return a.d<b.d;
}

inline bool cmp2(const flight&a,const flight&b){
	return a.d>b.d;
}

int main(){
	read(n),read(m),read(k);
	for(int i=1;i<=max_K;++i)pre[i]=suf[i]=-1;
	for(int i=1;i<=m;++i){
		int d,f,t,c;
		read(d),read(f),read(t),read(c);
		if(!f)fli[1].push_back({t,d,c});
		else fli[0].push_back({f,d,c});
	}
	std::sort(fli[0].begin(),fli[0].end(),cmp1);
	tmp=cnt=0;
	for(int i=1;i<=n;++i)f[i]=-1;
	for(auto cur:fli[0]){
		if(f[cur.x]==-1){
			++cnt;
			tmp+=(f[cur.x]=cur.w);
		}
		else if(f[cur.x]>cur.w){
			tmp-=(f[cur.x]-cur.w);
			f[cur.x]=cur.w;
		}
		if(cnt==n)pre[cur.d]=tmp;
	}
	for(int i=2;i<=max_K;++i)if(pre[i]==-1&&~pre[i-1])pre[i]=pre[i-1];
	std::sort(fli[1].begin(),fli[1].end(),cmp2);
	tmp=cnt=0;
	for(int i=1;i<=n;++i)f[i]=-1;
	for(auto cur:fli[1]){
		if(f[cur.x]==-1){
			++cnt;
			tmp+=(f[cur.x]=cur.w);
		}
		else if(f[cur.x]>cur.w){
			tmp-=(f[cur.x]-cur.w);
			f[cur.x]=cur.w;
		}
		if(cnt==n)suf[cur.d]=tmp;
	}
	for(int i=max_K-1;i;--i)if(suf[i]==-1&&~suf[i+1])suf[i]=suf[i-1];
	ans=-1;
	for(int i=2;i+k<=max_K;++i){
		if(pre[i-1]==-1||suf[i+k]==-1)continue;
		tmp=pre[i-1]+suf[i+k];
		if(ans==-1||ans>tmp)ans=tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}