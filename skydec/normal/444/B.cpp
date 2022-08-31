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
const int N=110000;
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
LL seed;int a[N],b[N];
int c[N];int n,d;
inline LL getnextX(){
	seed=(seed*37ll+10007)%1000000007;
	return seed;
}
inline void init(){
	rep(i,0,n-1)a[i]=i+1;
	rep(i,0,n-1)swap(a[i],a[getnextX()%(i+1)]);
	rep(i,0,n-1){
		if(i<d)b[i]=1;
		else b[i]=0;
	}
	rep(i,0,n-1)swap(b[i],b[getnextX()%(i+1)]);
}
int q[N];
int main(){
	scanf("%d%d%I64d",&n,&d,&seed);
	init();
	rep(i,0,n-1)if(b[i])q[++q[0]]=i;
	rep(i,0,n-1)c[a[i]]=i;
	rep(i,0,n-1){
		bool flag=0;int limit=n-30;if(limit<0)limit=1;
		per(j,n,limit)if(c[j]<=i&&b[i-c[j]]){
			printf("%d\n",j);
			flag=1;
			break;
		}
		if(!flag){
			int ma=0;
			rep(j,1,q[0])if(q[j]<=i)ma=Max(ma,a[i-q[j]]);
			printf("%d\n",ma);
		}
	}
	return 0;
}