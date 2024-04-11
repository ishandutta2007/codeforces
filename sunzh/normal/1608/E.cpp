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
int n;
int tot[3];
PII a[3][100010];
int ans;
const int inf=2e9;
bool dfs1(int st,int L,int x){
	// printf("%d,%d %d\n",st,L,x);
	if(st==(1<<3)-1) return 1;
	bool fl=0;
	for(int i=0;i<3;++i) if(!(st&(1<<i))){
		// printf("st:%d,i:%d\n",st,i);
		int o=upper_bound(a[i]+1,a[i]+tot[i]+1,mp(L,-inf))-a[i];
		if(o+x-1<=tot[i]){
			fl|=dfs1(st|(1<<i),a[i][o+x-1].fi+1,x);
			if(fl) return 1;
		}
	}return fl;
}
void solve1(){
	for(int i=0;i<3;++i) sort(a[i]+1,a[i]+tot[i]+1);
	int l=1,r=n/3;
	while(l<=r){
		int mid=l+r>>1;
		if(dfs1(0,-2e9,mid)){
			ans=max(ans,mid);l=mid+1;
		}else r=mid-1;
	}
}
int t1[100010],t2[100010];
int c1,c2;
bool check(int x){
	int p[3]={0,1,2};
	do{
		sort(a[p[0]]+1,a[p[0]]+tot[p[0]]+1,[&](PII x,PII y){
			return x.se>y.se;
		});
		int dw=a[p[0]][x].se;
		c1=c2=0;
		for(int i=1;i<=tot[1];++i) if(a[p[1]][i].se<dw){
			t1[++c1]=a[p[1]][i].fi;
		}
		for(int i=1;i<=tot[2];++i) if(a[p[2]][i].se<dw){
			t2[++c2]=a[p[2]][i].fi;
		}
		sort(t1+1,t1+c1+1);sort(t2+1,t2+c2+1);
		if(c1<x) continue ;
		int p=upper_bound(t2+1,t2+c2+1,t1[x])-t2;
		if(c2-p+1>=x) return 1;
	}while(next_permutation(p,p+3));
	return 0;
}
void solve2(){
	int l=1,r=n/3;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=max(ans,mid),l=mid+1;
		}else r=mid-1;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),c=read()-1;
		a[c][++tot[c]]=mp(x,y);
	}
	solve1();
	solve2();
	for(int i=1;i<=tot[0];++i) a[0][i].se=-a[0][i].se,a[1][i].se=-a[1][i].se,a[2][i].se=-a[2][i].se;
	solve2();
	for(int i=1;i<=tot[0];++i) a[0][i].se=-a[0][i].se,a[1][i].se=-a[1][i].se,a[2][i].se=-a[2][i].se;
	for(int i=1;i<=tot[0];++i){
		swap(a[0][i].fi,a[0][i].se);
		swap(a[1][i].fi,a[1][i].se);
		swap(a[2][i].fi,a[2][i].se);
	}
	solve1();solve2();
	for(int i=1;i<=tot[0];++i) a[0][i].se=-a[0][i].se,a[1][i].se=-a[1][i].se,a[2][i].se=-a[2][i].se;
	solve2();
	printf("%d\n",3*ans);
}