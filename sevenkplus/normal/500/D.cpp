#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010

int n; 
int px[N], py[N], pz[N];
vector<PII> A[N]; int q[N], fa[N], s[N];
double w[N];

int main () {
    cin >> n;
    for (int i = 0; i < n-1; i ++) {
        cin >> px[i] >> py[i] >> pz[i];
        px[i] --; py[i] --;
        A[px[i]].pb(mp(py[i], pz[i]));
        A[py[i]].pb(mp(px[i], pz[i]));
    }
    int l = 0, r = 1;
    q[0] = 0; fa[0] = -1;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < (int) A[x].size(); i ++) 
            if (fa[x] != A[x][i].fi) {
                fa[A[x][i].fi] = x;
                q[r++] = A[x][i].fi;
            }
    }
    for (int i = n-1; i >= 1; i --) {
        s[q[i]] ++; s[fa[q[i]]] += s[q[i]];
    }
    s[0] ++;
    double ms = (double)n*(n-1)*(n-2)/6;
    for (int i = 0; i < n-1; i ++) {
        int wx=  min(s[px[i]], s[py[i]]);
        int wy = n-wx;
        w[i] = (double) wx*wy*(wy-1)/2+(double)wy*wx*(wx-1)/2;
    }
    double S = 0;
    for (int i = 0; i < n-1; i ++) S += pz[i]*w[i];
    int _; cin >> _;
    while (_--) {
        int x, y;
        cin >> x >> y;
        x --;
        S -= pz[x]*w[x];
        pz[x] = y;
        S += pz[x]*w[x];
        printf ("%.9lf\n", S/ms*2);
    }
    return 0; 
}