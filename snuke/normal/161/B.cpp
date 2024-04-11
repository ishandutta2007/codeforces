#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 1005, INF = 100000000;

P x[MX], y[MX], ans[MX];
int xi, yi, ansi;
int ci, d[MX];
double sum;

int main(){
	int n, k, a, b;
	scanf("%d%d",&n,&k);
	
	rrep(i,n){
		scanf("%d%d",&a,&b);
		if(b==1){
			x[xi++] = P(a,i);
		} else {
			y[yi++] = P(a,i);
		}
	}
	sort(x,x+xi);
	sort(y,y+yi);
	
	int xj = -1, yj = -1;
	for(int i = xi-1; i >= 0; i--){
		if(ci == k-1){
			xj = i;
			break;
		}
		sum += 0.5*x[i].fi;
		d[ci] = x[i].se;
		ci++;
	}
	
	for(int i = yi-1; i >= 0; i--){
		if(ci==k-1){
			yj = i;
			break;
		}
		sum += y[i].fi;
		d[ci] = y[i].se;
		ci++;
	}
	
	rep(i,xj+1) sum += x[i].fi;
	rep(i,yj+1) sum += y[i].fi;
	
	a = INF;
	if(xj!=-1) a = x[0].fi;
	if(yj!=-1) a = min(a,y[0].fi);
	
	if(xj!=-1 && a != INF) sum -= 0.5*a;
	
	printf("%.1f\n",sum);
	rep(i,k-1){
		printf("1 %d\n",d[i]);
	}
	
	printf("%d",n-k+1);
	for(int i = 0; i <= xj; i++){
		printf(" %d",x[i].se);
	}
	for(int i = 0; i <= yj; i++){
		printf(" %d",y[i].se);
	}
	
	puts("");
	
	return 0;
}