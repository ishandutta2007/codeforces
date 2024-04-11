#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
vector<vector<int> >now,tmp;
int n,m;
int a[1510][1510];
int b[1510][1510];
bool used[1510];
bool check(int x){
	for(auto v:now){
		int lst=0;
		for(auto i:v){
//			printf("%d ",i);
			if(b[i][x]<lst) return 0;
			lst=b[i][x];
		}
//		printf("\n");
	}
	return 1;
}
void solve(int x){
	for(auto v:now){
		int l=0,r;
		for(l;l<v.size();l=r){
			r=l+1;
			while(r<v.size()&&b[v[r]][x]==b[v[l]][x]) ++r;
			vector<int>t;
			for(int i=l;i<r;++i) t.pb(v[i]);
			tmp.pb(t);
		}
	}
	now.clear();
	now=std::move(tmp);
	tmp.clear();
}
int id[2010];
void doit(int x){
	auto cmp=[&](int y,int z){
		return a[y][x]<a[z][x];
	};
	stable_sort(id+1,id+n+1,cmp);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		id[i]=i;
		for(int j=1;j<=m;++j) a[i][j]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) b[i][j]=read();
	}
	vector<int>v(n);
	for(int i=0;i<n;++i) v[i]=i+1;
	now.pb(v);
	vector<int>ans;
	while(1){
		for(auto it=now.begin();it!=now.end();){
			if((*it).size()==1){
				now.erase(it);
			}
			else ++it;
		}
		if(now.size()==0) break ;
		bool f=0;
		for(int i=1;i<=m;++i){
			if(!used[i]&&check(i)){
//				printf("i:%d\n",i);
				solve(i);used[i]=1;ans.pb(i);f=1;break ;
			}
		}
		if(!f) break ;
	}
//	printf("%d\n",check(2));
//	for(auto v:now){
//		for(int i:v) printf("%d ",i);
//		printf("\n");
//	}
	reverse(ans.begin(),ans.end());
	for(int x:ans) doit(x);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[id[i]][j]!=b[i][j]){
				printf("-1\n");exit(0);
			}
		}
	}
	printf("%d\n",ans.size());
	for(int x:ans) printf("%d ",x);printf("\n");
}