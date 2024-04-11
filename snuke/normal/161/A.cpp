#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 100000000;

P a[MX], b[MX], ans[MX]; int ansi;

int main(){
	int n, m, x, y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	
	rep(k,n){ scanf("%d",&a[k].fi); a[k].se = k;}
	rep(k,m){ scanf("%d",&b[k].fi); b[k].se = k;}
	sort(a,a+n);
	sort(b,b+m);
	
	int i = 0, j = 0;
	while(i<m&&j<n){
		if(a[j].fi-x > b[i].fi){
			i++;
		} else if(a[j].fi+y < b[i].fi){
			j++;
		} else {
			ans[ansi++] = P(a[j].se,b[i].se);
			i++; j++;
		}
	}
	
	printf("%d\n",ansi);
	rep(k,ansi) printf("%d %d\n",ans[k].fi+1,ans[k].se+1);
	
	return 0;
}