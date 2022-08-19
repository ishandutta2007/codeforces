#include<cstdio>
#include<queue>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 4005, MT = 86401, INF = 100000;

int n, k, s, ans;
P p[MX], x;
int e[MX];

int main(){
	scanf("%d%d",&n,&k);
	
	rep(i,n) scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p,p+n);
	rep(i,n) e[i] = p[i].fi+p[i].se;
	
	s = 1;
	rep(i,n){
		ans = max(ans,p[i].fi-s);
		
		if(k) k--; else {
			x = P(INF,0);
			rep(j,i+1) x = min(x,P(e[j],j));
			s = x.fi;
			e[x.se] = INF;
			rep(j,n){
				if(e[j] == INF) continue;
				if(x.se < j){
					e[j] = max(e[j],s+p[j].se);
				} else {
					e[j] += p[x.se].se;
				}
			}
		}
		//printf("%d\n",s);
	}
	
	printf("%d\n",max(ans,MT-s));
	
	return 0;
}