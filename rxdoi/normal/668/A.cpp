//   Author:Arturia
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=a;x<=(int)(b);x++)
#define drp(x,a,b) for (int x=a;x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
using namespace std;
inline ll rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int maxn=105;
PII ps[maxn][maxn];
int ans[maxn][maxn],n,m,q;
int main(){
	n=rd(),m=rd(),q=rd();
	rep(i,1,n) rep(j,1,m) ps[i][j]=mk(i,j);
	rep(i,1,q){
		int t=rd();
		if (t==1){
			int ri=rd();
			PII tmp=ps[ri][1];
			rep(j,1,m-1) ps[ri][j]=ps[ri][j+1];ps[ri][m]=tmp; 
		}
		if (t==2){
			int ci=rd();
			PII tmp=ps[1][ci];
			rep(j,1,n-1) ps[j][ci]=ps[j+1][ci];ps[n][ci]=tmp;
		}
		if (t==3){
			int r=rd(),c=rd(),x=rd();
			ans[ps[r][c].fs][ps[r][c].sc]=x;
		}
	}
	rep(i,1,n){
		rep(j,1,m) rt(ans[i][j]),putchar(' ');
		putchar('\n');
	}
}