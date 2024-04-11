#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII; 
typedef long long ll; 

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define N 100010
#define L 17

struct P {
    ll x, y; 
    
    P () {} 
    P (ll _x, ll _y):x(_x), y(_y) {}
    
    P operator - (const P&a) const {return P(x-a.x, y-a.y); }
    
    ll crs (const P&a) {
        return x*a.y - y*a.x; 
    }
    
    void get () {
        scanf("%I64d%I64d", &x, &y); 
    }
}; 

int n; P a[N]; 
int f[N]; 

int st[N]; int sn; 

bool bet (P x, int p1, int p2) {
    return (a[p1]-x).crs(a[p2]-x) <= 0; 
}

int ff (P x) {
    int le = 0; 
    int ri = sn-2; 
    while (le <= ri) {
        int mid = (le+ri)/2; 
        if (bet(x, st[mid+1], st[mid]))
            le = mid+1;
        else
            ri = mid-1; 
    }
    return st[ri+1]; 
}

vector<int> c[N]; int d[N]; 
int fa[N][L]; int fl[N], fr[N]; 

void gg(int x) {
    static int t = 0; 
    fl[x] = t ++; 
    fa[x][0] = f[x]; 
    for (int i = 1; i < L; i ++) 
        fa[x][i] = fa[fa[x][i-1]][i-1]; 
    
    for (vector<int>::iterator i = c[x].begin(); i != c[x].end(); i ++) {
        d[*i] = d[x] + 1; 
        gg(*i); 
    }
    fr[x] = t ++; 
}

int goup(int x, int y) {
    for (int i = 0; i < L; i ++) 
        if ((y>>i)&1) x = fa[x][i];
    return x; 
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y); 
    x = goup(x, d[x]-d[y]); 
    if (x == y) return x; 
    for (int i = L-1; i >= 0; i --) 
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i]; 
            y = fa[y][i]; 
        }
    return f[x]; 
}

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i ++) a[i].get(); 
    
    for (int i = n-1; i >= 0; i --) {
        if (i != n-1) f[i] = ff(a[i]); 
        else f[i] = n; 
        while (sn >= 2 && (a[st[sn-1]]-a[i]).crs(a[st[sn-2]]-a[st[sn-1]]) >= 0) sn --; 
        st[sn++] = i; 
    }
    
    f[n-1] = n-1; 
    for (int i = 0; i < L; i ++) fa[n-1][i] = n-1; 
    
    for (int i = 0; i < n-1; i ++) 
        c[f[i]].pb(i); 
    gg(n-1); 
    
    int q; scanf("%d", &q); 
    while (q --) {
        int x, y; scanf("%d%d", &x, &y); 
        printf ("%d%c", lca(x-1, y-1)+1, q == 0?'\n':' '); 
    }
    return 0; 
}