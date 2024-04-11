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
struct node{
	int id,a,b;
	bool operator <(const node &x){
		return a<x.a;
	}
}a[100010];
int ans[100010];
int pmx[100010],smx[100010];
int B[100010],id[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i].a=read(),ans[i]=0,a[i].id=i;
		for(int i=1;i<=n;++i) a[i].b=read(),B[i]=a[i].b;
		sort(B+1,B+n+1);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i) a[i].b=lower_bound(B+1,B+n+1,a[i].b)-B,id[a[i].b]=i;
		pmx[0]=smx[0]=0;
		for(int i=1;i<=n;++i) pmx[i]=max(pmx[i-1],a[i].b),smx[i]=max(smx[i-1],id[i]);
		ans[a[n].id]=1;
		for(int i=n-1;i>=1;--i){
			ans[a[i].id]=ans[a[smx[pmx[i]]].id];
		}
		for(int i=1;i<=n;++i) printf("%d",ans[i]);printf("\n");
	}
}