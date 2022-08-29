#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
struct jdb{int x,y;db jj;}a[MAXN];
int n;
bool cmp(jdb x,jdb y){return x.jj<y.jj;}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].jj=(180.0/acos(-1.0))*atan2(a[i].y,a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	a[n+1].jj=a[1].jj+360;db ans=361;
	rep(i,1,n)ans=min(ans,360-a[i+1].jj+a[i].jj);
	printf("%.8lf\n",ans);
}