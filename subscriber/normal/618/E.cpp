#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 611111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;

int ty[N], id[N], pr[N];

int intr[N], next[N];

double len[N];

int an[N], tan2[N];

const int mg = 666;

double xx[N], yy[N];

double cos2[360], sin2[360];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		len[i] = 1;
		an[i] = 0;
	}

	for (int i = 0; i < 360; i++) {
		cos2[i] = cos(i / 180. * acos(-1));
		sin2[i] = sin(i / 180. * acos(-1));
	}

	for (int i = 0; i < m; i++) cin >> ty[i] >> id[i] >> pr[i];

	for (int s = 0; s < m; s += mg) {
		int en = min(m, s + mg);

		for (int i = 0; i <= n; i++) intr[i] = 0;

		for (int i = s; i < en; i++) {
			intr[id[i] - 1] = 1;
		}
		intr[n - 1] = 1;

		int g = 0;
		while (g < n) {
			if (intr[g]) {
				g++;
				continue;
			}
			
			int u = 0;
			double x = 0;
			double y = 0;

			int gg = g;
			while (!intr[gg]) {
				u = (u + an[gg] + 360) % 360;

				x += cos2[u] * len[gg];
				y += sin2[u] * len[gg];

				gg++;
			}

			xx[g] = x;
			yy[g] = y;

			tan2[g] = u;

			next[g] = gg;
			g = gg;

		}

		for (int i = s; i < en; i++) {
			if (ty[i] == 1) {
//				len2[id[i] - 1] += pr[i];
				len[id[i] - 1] += pr[i];
			} else {
//				tan2[id[i] - 1] -= pr[i] / 180. * acos(-1);
				an[id[i] - 1] =(an[id[i] - 1] - pr[i] + 360) % 360;
			}
			int g = 0;
			double x = 0;
			double y = 0;
			int u = 0;
			while (g < n) {
				if (intr[g]) {
					u = (u + an[g] + 360) % 360;
					x += cos2[u] * len[g]; 
					y += sin2[u] * len[g]; 
					g++;
				} else {
					x += cos2[u] * xx[g] - sin2[u] * yy[g];
					y += sin2[u] * xx[g] + cos2[u] * yy[g];

					u = (u + tan2[g] + 360) % 360;
					g = next[g];
				}					
			}
			printf("%.10lf %.10lf\n", x, y);
		}
	}

	return 0;
}