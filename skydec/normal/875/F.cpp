#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int n,m;
struct ww{
	int a,b,w;
}bb[N];
inline bool cmp(const ww &a,const ww &b){return a.w>b.w;}
int fa[N];
bool is[N];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&bb[i].a,&bb[i].b,&bb[i].w);
	}
	sort(bb+1,bb+1+m,cmp);
	rep(i,1,n)fa[i]=i;
	LL ans=0;
	rep(i,1,m){
		if(get(bb[i].a)!=get(bb[i].b)){
			int x=get(bb[i].a);
			int y=get(bb[i].b);
			if(is[x]&&is[y])continue;
			fa[x]=y;
			is[y]|=is[x];
			ans+=bb[i].w;
		}
		else{
			int x=get(bb[i].a);
			if(is[x])continue;
			is[x]=1;
			ans+=bb[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}