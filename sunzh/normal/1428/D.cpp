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
int n;
int a[100010];
int nxt[100010];
vector<PII>ans;
set<int>st1,st2,st3;
int used[100010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int fir=1;
	while(fir<=n&&a[fir]<=1) ++fir;
	if(fir>n){
		int pos=n;
		int siz=0;
		for(int i=1;i<=n;++i) if(a[i]==1){
			++siz;ans.pb(mp(pos,i));--pos;
		}
		printf("%d\n",siz);
		for(auto i:ans) printf("%d %d\n",n-i.fi+1,i.se);
		return 0;
	}
	int pos=fir;
	for(int i=fir+1;i<=n;++i){
		if(a[i]>1){
			if(a[i]==2) st2.insert(i);else st3.insert(i);
			nxt[pos]=i;pos=i;
		}
		else if(a[i]==1){
			st1.insert(i);
		}
	}
	pos=n;
	int x=fir;
	int siz=0;
	bool f=0;int lst=-1;
	while(x){
		ans.pb(mp(pos,x));++siz;
		if(a[x]==3){
			auto it0=st3.lower_bound(x+1);
			if(it0!=st3.end()){
				++siz;ans.pb(mp(pos,*it0));st3.erase(it0);
			}
			else{
				auto it1=st2.lower_bound(x);
				if(it1==st2.end()){
					auto it2=st1.lower_bound(x);
					if(it2==st1.end()) f=1;
					else {
						used[*it2]=2;
						++siz;ans.pb(mp(pos,*it2));st1.erase(it2);
					}
				}
				else{
					++siz;
					ans.pb(mp(pos,*it1));
					st2.erase(it1);
				}
			}
		}
		else{
			auto it=st1.lower_bound(x);
			if(it==st1.end()) f=1;
			else {
				used[*it]=1;
				++siz;ans.pb(mp(pos,*it));
				st1.erase(it);
			}
		}
		--pos;
		x=nxt[x];
	}
	if(f){
		printf("-1\n");return 0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==1){
			if(used[i]==2||used[i]==0){
				ans.pb(mp(pos--,i));
				++siz;
			}
		}
	}
	printf("%d\n",siz);
	for(auto i:ans) printf("%d %d\n",n-i.fi+1,i.se);
}