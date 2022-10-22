#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
vector<int>vec[200010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			int x=read();
			vec[x].pb(i);
		}
		int p=1;
		vector<int>ans;
		while(p<=n){
			int nw=-1,mx=p;
			for(int i=0;i<=n;++i){
				int t=lower_bound(vec[i].begin(),vec[i].end(),p)-vec[i].begin();
				if(t<vec[i].size()){
					++nw;mx=max(mx,vec[i][t]);
				}
				else break ;
			}ans.pb(nw+1),p=mx+1;
		}
		printf("%d\n",ans.size());
		for(int i:ans) printf("%d ",i);printf("\n");
		for(int i=0;i<=n;++i) vector<int>().swap(vec[i]);
	}
}