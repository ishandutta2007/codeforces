#include<cstdio>
#include<map>
#include<utility>
#include<iostream>
using namespace std;
int T,n,l,r,c,mn,mx,L,R;map<pair<int,int>,int> mp;
int main(){
	for(scanf("%d",&T);T--;mp.clear()){
		scanf("%d",&n);
		scanf("%d%d%d",&l,&r,&c);mp[make_pair(L=l,R=r)]=c;
		printf("%d\n",mn=mx=c);
		for(;--n;){
			scanf("%d%d%d",&l,&r,&c);
			if(mp.count(make_pair(l,r))) mp[make_pair(l,r)]=min(mp[make_pair(l,r)],c);
			else mp[make_pair(l,r)]=c;
			if(l<L) L=l,mn=c;
			if(r>R) R=r,mx=c;
			if(l==L) mn=min(mn,c);
			if(r==R) mx=min(mx,c);
			if(mp.count(make_pair(L,R))) printf("%d\n",min(mn+mx,mp[make_pair(L,R)]));
			else printf("%d\n",mn+mx);
		}
	}
	return 0;
}