#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
#include<ctime>
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
int n,m,k;
struct c{
	int v,w;
}; 
vector<c>vec[200010];
bool cmp(c x,c y){
	return x.w<y.w;
}
int s1,s2;
int rnd1[200010],rnd2[200010];
int sum1[12][12],sum2[12][12];
mt19937 rnd(time(NULL));
mt19937 rd(998244353) ;
int ans;
void dfs(int x,int y,int z){
	if(x==k+1){
		ans+=(y==s1&&z==s2);return ;
	}
	for(int i=0;i<x;++i){
		dfs(x+1,y^sum1[x][i],z+sum2[x][i]);
	}
}
signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		vec[u].push_back((c){v,w});
	}
	for(int i=1;i<=n;++i){
		rnd1[i]=rd();
		s1^=rnd1[i];
		rnd2[i]=rnd();
//		rnd2[i]%=998244353;
//		print(rnd1[i]);putchar(' ');print(rnd2[i]);putchar('\n');
		s2+=rnd2[i];
	}
	for(int i=1;i<=n;++i){
		sort(vec[i].begin(),vec[i].end(),cmp);
		int degr=vec[i].size();
//		printf("i:%d,d:%d\n",i,degr);
		for(int j=0;j<vec[i].size();++j){
			int v=vec[i][j].v;
			sum1[degr][j]^=rnd1[v];sum2[degr][j]+=rnd2[v];
		}
	}
	dfs(1,0,0);
	print(ans);
}