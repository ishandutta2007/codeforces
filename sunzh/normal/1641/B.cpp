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
int a[510],b[510];
int cnt[510];
vector<int>ans;
vector<PII>op;
int pr;
void addans(int t){
	pr+=t*2;
	ans.pb(t*2);
}
vector<int>vec;
void doit(int pos,int k){
	op.pb(mp(pos,b[k]));vec.pb(k);
}
int main(){
	T=read();
	while(T--){
		n=read();ans.clear();op.clear();vec.clear();
		for(int i=1;i<=n;++i) a[i]=b[i]=read();
		sort(b+1,b+n+1);pr=0;
		int m=unique(b+1,b+n+1)-b-1;
		bool fl=0;
		for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+m+1,a[i])-b,++cnt[a[i]];
		// for(int i=1;i<=n;++i) printf("%d\n",a[i]);
		for(int i=1;i<=m;++i) if(cnt[i]&1) fl=1;
		for(int i=1;i<=m;++i) cnt[i]=0;
		if(fl){
			printf("-1\n");continue ;
		}
		for(int i=n;i>=1;--i) vec.pb(a[i]);
		int cnt=0;
		while(vec.size()){
			if(cnt>n*n){
				fl=1;break ;
			}
			int p=vec.back();vec.pop_back();
			// printf("p:%d\n",p);
			vector<int>Left;
			// printf("%d\n",vec.back());
			while(vec.size()&&vec.back()!=p){
				Left.pb(vec.back());vec.pop_back();
			}
			if(!vec.size()||vec.back()!=p){
				fl=1;break ;
			}
			int len=Left.size()+1;
			vec.pop_back();
			// printf("len:%d\n",len);
			for(int i=0;i<Left.size();++i){
				if(!vec.size()||vec.back()!=Left[i]) doit(pr+len+1+i,Left[i]);
				else vec.pop_back();
			}
			addans(len);
		}
		if(fl){
			printf("-1\n");continue ;
		}
		printf("%d\n",op.size());
		for(PII i:op) printf("%d %d\n",i.fi,i.se);
		printf("%d\n",ans.size());
		for(int i:ans) printf("%d ",i);printf("\n");
	}
}