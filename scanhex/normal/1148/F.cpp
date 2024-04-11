#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#pragma GCC optimize("Ofast")

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
int n;
int val[N];
nagai msk[N];
using uint=unsigned int;
uint seed=239239239;
uint xrand(){
	seed^=seed<<2;
	seed^=seed>>7;
	seed^=seed<<7;
	return seed;
}
#define pc(x) __builtin_popcountll(x)
nagai calc(nagai m){
	nagai s1=0;
	for(int i=0;i<n;++i){
		 nagai kek=msk[i]&m;
		 if(pc(kek)&1)
			 s1-=val[i];
		 else
			 s1+=val[i];
	}
	if(s1<0){
		cout<<m<<'\n';
		exit(0);
	}
	return s1;
}
mt19937 rnd(228);
const int LG=62;
void solve1(){
	nagai m=0;
	nagai cur=calc(m);
	vector<int>ord(LG);
	iota(ord.begin(),ord.end(),0);
	for(int i=0;i<3;++i){
		shuffle(ord.begin(),ord.end(),rnd);
		for(int i:ord){
			nagai kek=calc(m^1LL<<i);
			if(kek<cur)
				cur=kek,m^=1LL<<i;
		}
	}
}
void solve2(){
	calc((1LL<<LG)-1);
	for(int i=0;i<LG;++i){
		calc(1LL<<i);
		calc(((1LL<<LG)-1)^1LL<<i);
	}
}
nagai xtime(){
	return clock()*1000/CLOCKS_PER_SEC;
}
void solve3(){
	while(xtime()<1800){
		nagai msk=0;
		for(int i=0;i<LG;++i)
			msk^=nagai(xrand()&1)<<i;
		calc(msk);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>val[i]>>msk[i];
	nagai s=accumulate(val,val+n,0LL);
	if(s<0)
		for(int i=0;i<n;++i)
			val[i]*=-1;
	solve1();
	solve2();
	solve3();
	return 0;
}