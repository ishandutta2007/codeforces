#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#define PIp pair<int,pair<int,int> > 
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
int l[200010],r[200010],t[200010];
vector<PIp>vec;
set<PII>s[2];
int ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read(),t[i]=read()-1;
		vec.pb(mp(l[i],mp(0,i)));
		vec.pb(mp(r[i],mp(1,i)));
	}
	sort(vec.begin(),vec.end());
	for(auto i:vec){
		if(i.se.fi){
			if(s[t[i.se.se]].count(mp(r[i.se.se],i.se.se))){
				if(s[t[i.se.se]^1].size()){
					++ans;s[t[i.se.se]^1].erase(s[t[i.se.se]^1].begin());
				}
				s[t[i.se.se]].erase(mp(r[i.se.se],i.se.se));
			}
		}
		else s[t[i.se.se]].insert(mp(r[i.se.se],i.se.se));
	}
	print(n-ans);
}