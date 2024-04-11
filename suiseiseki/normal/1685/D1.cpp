#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

const int Maxn=200;
int n;
namespace DSU{
	int fa[Maxn+5],sz[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i,sz[i]=1;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x,sz[fa_x]+=sz[fa_y];
	}
}
int p[Maxn+5],q[Maxn+5],a[Maxn+5];
int pos[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		q[i]=p[i];
	}
	DSU::init();
	for(int i=1;i<=n;i++){
		DSU::merge(i,p[i]);
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(DSU::find(i)==i){
			num++;
		}
	}
	while(1){
		bool flag=0;
		DSU::init();
		for(int i=1;i<=n;i++){
			DSU::merge(i,p[i]),pos[p[i]]=i;
		}
		for(int i=1;i<n;i++){
			if(DSU::find(i)!=DSU::find(i+1)){
				flag=1;
				int a=pos[i],b=pos[i+1];
				std::swap(p[a],p[b]);
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	a[n]=1;
	for(int i=n-1;i>0;i--){
		a[i]=p[a[i+1]];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}