#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
map<int,int>np;
const int N=110000;
int fa[N];
int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
int n,a,b;
int nd[N],st[N];int p[N];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n){scanf("%d",&p[i]);np[p[i]]=i;fa[i]=i;st[i]=3;}
	rep(i,1,n){
		if(np.count(a-p[i]))fa[get(np[a-p[i]])]=get(i),nd[i]|=1;
		if(np.count(b-p[i]))fa[get(np[b-p[i]])]=get(i),nd[i]|=2;
	}
	rep(i,1,n)st[get(i)]&=nd[i];
	rep(i,1,n)if(!st[i]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	rep(i,1,n){
		printf("%d ",((st[get(i)]&1)==0));
	}
	return 0;
}