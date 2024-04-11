#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#define int long long
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
struct node{
	int a,t;
}a[200010];
bool cmp(node x,node y){
	return x.t>y.t;
}
set<int>st;
map<int,bool>mp;
set<int>::iterator it;
int ans; 
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].a=read();
	for(int i=1;i<=n;++i) a[i].t=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(!mp.count(a[i].a)){
			it=st.lower_bound(a[i].a);if((*it)==a[i].a) st.erase(it);mp[a[i].a]=1;if(!mp.count(a[i].a+1)) st.insert(a[i].a+1);
		}
		else{
			it=st.lower_bound(a[i].a);
			if(!mp.count((*it)+1)) st.insert((*it)+1);
			mp[(*it)]=1;ans+=((*it)-a[i].a)*a[i].t;st.erase(it);
		}
	}
	printf("%lld\n",ans);
}