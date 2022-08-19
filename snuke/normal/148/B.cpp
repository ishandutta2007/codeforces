#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef pair<int,int> P;
typedef long long int ll;

const int MX = 10000, INF = 100000000;
const double eps = 1e-10;

bool b[100001];

int main(){
	int v, w, t, f, c;
	
	scanf("%d%d%d%d%d",&v,&w,&t,&f,&c);
	
	if(w <= v){ printf("0\n"); return 0;}
	double d = double(v*t)/(w-v)+t;
	if((double)c/v <= d+eps){ printf("0\n"); return 0;}
	
	int ans = 1;
	for(;; ans++){
		d += d*v/w+f;
		d += d*v/(w-v);
		if((double)c/v <= d+eps) break;
	}
	
	printf("%d\n",ans);
	
	return 0;
}