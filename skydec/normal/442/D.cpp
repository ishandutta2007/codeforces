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
const int N=1100000;
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
struct info{
	pii ma1,ma2;
	int g;
	inline bool add(pii pa){
		if(ma1.se==pa.se)ma1=pa;
		else if(ma2.se==pa.se){
			ma2=pa;
			if(ma2>ma1){
				pii tmp=ma2;ma2=ma1;ma1=tmp;
			}
		}
		else{
			if(pa>ma2){
				ma2=pa;
				if(ma2>ma1){
					pii tmp=ma2;ma2=ma1;ma1=tmp;
				}
			}
		}
		if(Max(ma1.fi,ma2.fi+1)>g){
			g=Max(ma1.fi,ma2.fi+1);
			return true;
		}
		return false;
	}
}f[N];
int fa[N];
int n;
int main(){
	scanf("%d",&n);n++;
	rep(i,1,n)f[i].g=1;
	rep(i,2,n){
		scanf("%d",&fa[i]);
		int now=i;
		while(1){
			if(now==1)break;
			if(f[fa[now]].add(pii(f[now].g,now)))now=fa[now];
			else break;
		}
		printf("%d\n",f[1].ma1.fi);
	}
}