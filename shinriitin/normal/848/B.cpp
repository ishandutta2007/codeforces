#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

const int max_N=2e5,max_L=1e5,BASE=1e5;

typedef std::pair<int,int>pair;

typedef std::vector<int>vector;

int n,w,h,g[max_N+21],p[max_N+21],t[max_N+21];

vector group_x[max_N+21],group_y[max_N+21];

pair ans[max_N+21];

std::vector<pair>tmp;

inline void solve(int index){
	auto&Gx=group_x[index];
	auto&Gy=group_y[index];
	if(Gx.size()+Gy.size()==0)return;
	std::sort(Gx.begin(),Gx.end(),[&](int x,int y){return p[x]>p[y];});
	std::sort(Gy.begin(),Gy.end(),[&](int x,int y){return p[x]<p[y];});
	tmp.clear();
	for(auto it:Gy)tmp.push_back({w,p[it]});
	for(auto it:Gx)tmp.push_back({p[it],h});
	int cnt=0;
	for(auto it:Gx)ans[it]=tmp[cnt++];
	for(auto it:Gy)ans[it]=tmp[cnt++];
}

int main(){
	read(n),read(w),read(h);
	for(int i=1;i<=n;++i){
		read(g[i]),read(p[i]),read(t[i]);
		int index=p[i]-t[i]+BASE;
		if(g[i]==1)group_x[index].push_back(i);
		else group_y[index].push_back(i);
	}
	for(int i=0;i<=BASE*2;++i)solve(i);
	for(int i=1;i<=n;++i)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;	
}