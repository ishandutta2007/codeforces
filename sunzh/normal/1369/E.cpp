#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int w[100010];
PII a[200010];
set<PII>st;
multiset<int>trans;
bool vis[200010];
vector<int>ans,vec[200010];
int s[100010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) w[i]=read();
	for(int i=1;i<=m;++i){
		a[i].fi=read(),a[i].se=read();
		++s[a[i].fi],++s[a[i].se];vec[a[i].fi].pb(i),vec[a[i].se].pb(i);
	}
	for(int i=1;i<=n;++i) st.insert(mp(w[i]-s[i],i));
	while(ans.size()<m&&st.size()){
//		printf("%d\n",st.size());
		auto it=st.lower_bound(mp(0,0));
		trans.clear();
		if(it==st.end()) break ;
		for(int i:vec[it->se]){
			if(vis[i]) continue ;
			vis[i]=1;
			ans.pb(i);
			int v=a[i].fi+a[i].se-(it->se);
			trans.insert(v);
		}
		st.erase(it);
		for(auto it2=trans.begin();it2!=trans.end();++it2){
			int i=*it2;
			int d=w[i]-s[i];
			auto it1=st.lower_bound(mp(d,i));
			if(it1->second==i){
				st.erase(it1);st.insert(mp(d+1,i));--s[i];
			}
		}
	}
	if(ans.size()<m) printf("DEAD\n");
	else{
		printf("ALIVE\n");
		for(int i=m-1;i>=0;--i) printf("%d ",ans[i]);
	}
}