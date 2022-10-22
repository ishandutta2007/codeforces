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
int a[200010],cnt[200010];
vector<int>vec[200010];
int p[200010];
int main(){
	T=read();
	for(int o=1;o<=T;++o){
		n=read();
		for(int i=1;i<=n;++i) cnt[i]=p[i]=0,vector<int>().swap(vec[i]);
		for(int i=1;i<=n;++i) a[i]=read(),++cnt[a[i]],vec[cnt[a[i]]].pb(i);
		for(int i=1;i<=n;++i) if(vec[i].size()){
			sort(vec[i].begin(),vec[i].end(),[&](int x,int y){return a[x]<a[y];}); 
			for(int j=0;j<vec[i].size();++j){
				p[vec[i][j]]=vec[i][j==vec[i].size()-1?0:j+1];
			}
		}
		for(int i=1;i<=n;++i) printf("%d ",a[p[i]]);printf("\n");
	}
}