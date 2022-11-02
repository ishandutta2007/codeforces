#include <bits/stdc++.h>

const double pi=acos(-1.);

typedef long long ll;

const int max_N=1e3;

std::unordered_set<ll>set;

struct poi{
	int d[5];
	inline void init(){
		for(int i=0;i<5;++i)scanf("%d",d+i);	
	}
}p[max_N+21];

int n;

bool ban[max_N+21];

inline bool check(int a,int b,int c){
	poi ab,ac;
	for(int i=0;i<5;++i){
		ab.d[i]=p[b].d[i]-p[a].d[i];
		ac.d[i]=p[c].d[i]-p[a].d[i];
	}
	double abac=0,AB=0,AC=0;
	for(int i=0;i<5;++i){
		abac+=ab.d[i]*ac.d[i];
		AB+=ab.d[i]*ab.d[i];
		AC+=ac.d[i]*ac.d[i];	
	}
	AB=std::sqrt(AB);
	AC=std::sqrt(AC);
	double angle=acos(abac/AB/AC);
	return angle*2<pi;
}

std::vector<int>ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)p[i].init();
	if(n>100)return puts("0"),0;
	for(int a=1;a<=n;++a)
		for(int b=1;b<=n;++b)if(a!=b)
			for(int c=1;c<=n;++c)if(a!=c){
				if(b==c)continue;
				if(check(a,b,c))ban[a]=1;	
			}
	for(int i=1;i<=n;++i)if(!ban[i])ans.push_back(i);
	int ans1=ans.size();
	printf("%d\n",ans1);
	for(int i=0;i<ans1;++i)printf("%d\n",ans[i]);
	return 0;
}