#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,p;
int ans[100010];
int tm[100010];
priority_queue<PII>Q1;
priority_queue<int>Q2; 
set<int>st;
signed main(){
	n=read(),p=read();
	for(int i=1;i<=n;++i) tm[i]=read(),Q1.push(mp(-tm[i],-i));
	int nowt=0,et=0;
	while(Q1.size()){
		PII u=Q1.top();Q1.pop();
		nowt=-u.fi;
		if(u.se<-n){
			st.erase(-u.se-n);
		}
		else Q2.push(u.se);
		while(!Q2.empty()&&(st.empty()||-Q2.top()<*st.begin())){
			int u=-Q2.top();Q2.pop();
			st.insert(u);
			et=max(et,nowt)+p;
			Q1.push(mp(-et,-n-u));
			ans[u]=et;
		}
	}
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
}