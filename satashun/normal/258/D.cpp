#include <cstdio>

using namespace std;

#define rep(i, m) for(int i = 0; i < (int)m; ++i)

int n, m;
int a[1010];
double ret;
double p[1010][1010];

int main(){
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) rep(j, n) if(i != j) p[i][j] = (a[i] > a[j] ? 1.0 : 0.0);
    while(m--){
	int a, b; scanf("%d %d", &a, &b); --a; --b;
	p[a][b] = p[b][a] = 0.5;
	rep(i, n) if(i != a && i != b){
	    p[i][a] = p[i][b] = (p[i][a] + p[i][b]) / 2.0;
	    p[a][i] = p[b][i] = 1.0 - p[i][a];
	}
    }
    rep(i, n) rep(j, i) ret += p[j][i];
    printf("%.8lf\n", ret);
    return 0;
}