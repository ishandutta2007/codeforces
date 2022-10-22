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
#include<random>
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
int n,k;
char str[1010][1010];
set<int>vec[2010];
bool used[2010][2010],ans[2010][2010];
// int cnt[2010];
int Lst[2010];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
		for(int i=1;i<=n+n;++i) for(int j=1;j<=n;++j) used[i][j]=0,ans[i][j]=0;
		for(int i=1;i<=n+n;++i) set<int>().swap(vec[i]),Lst[i]=0;
		for(int i=1;i<=n-k+1;++i){
			int sx=n-k+1-i+1;
			for(int j=1;j<sx;++j) vec[i].insert(j);
			for(int j=sx;j<=n;++j) if(str[j][j-sx+1]=='1') vec[i].insert(j);
		}
		for(int i=2;i<=n-k+1;++i){
			int sy=i;
			for(int j=1;j<=n-i+1;++j) if(str[j][j+i-1]=='1') vec[i+n-k].insert(j);
		}
		bool f=1;
		for(int i=1;i<=n-k+1;++i){
			int lst=0;
			for(int j=1;j<n-k+1;++j){
				auto it=vec[j].lower_bound(max(lst,max(Lst[j]+1,Lst[j+1]+1)));
				if(it==vec[j].end()){
					f=0;break ;
				}
				// printf("i:%d,j:%d,%d\n",i,j,*it);
				used[j][*it]=1;lst=Lst[j]=(*it);vec[j].erase(it);
			}
			for(int j=n-k+1;j<=n-k+n-k+2;++j){
				// printf("i:%d,j:%d,%d\n",i,j-n+k,n-(j-(n-k))+1-i);
				if(n-(j-(n-k))+1-i<k-1) break ;
				// printf("i:%d,j:%d\n",i,j-n+k);
				auto it=vec[j].lower_bound(max(lst,max(Lst[j]+1,Lst[j+1]+1)));
				if(it==vec[j].end()){
					f=0;break ;
				}
				used[j][*it]=1;lst=Lst[j]=(*it);vec[j].erase(it);
			}
		}
		if(!f){
			printf("NO\n");continue ;
		}
		for(int i=1;i<=n-k+1;++i){
			int sx=n-k+1-i+1;
			for(int j=sx;j<=n;++j) if(used[i][j]) ans[j][j-sx+1]=1;
		}
		for(int i=2;i<=n-k+1;++i){
			for(int j=1;j<=n-i+1;++j) if(used[i+n-k][j]) ans[j][j+i-1]=1;
		}
		printf("Yes\n");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) printf("%1d",ans[i][j]^1);printf("\n");
		}
	}
}