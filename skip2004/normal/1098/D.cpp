#include<cstdio>
#include<set>
#include<iostream>
typedef long long ll;
struct set{
	ll sum;
	std::multiset<int>s;
	inline void ins(int x){sum+=x,s.insert(x);}
	inline void del(int x){sum-=x,s.erase(s.find(x));}
	inline int getmin(){return *s.begin();}
	inline ll getsum(){return sum;}
	inline set(){sum=0;}
}s[40];
int n,q;
inline int lg(int x){return x==1?1:lg(x>>1)+1;}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> q;
	while(q--){
		char opt;int x;
		std::cin >> opt >> x;
		set&p=s[lg(x)];
		if(opt=='+')p.ins(x),++n;
		else p.del(x),--n;
		ll sm=0,ans=n;
		for(int i=1;i<=30;++i){
			ans-=sm * 2 < s[i].getmin();
			sm += s[i].getsum();
		}
		std::cout << ans << '\n';
	}
}