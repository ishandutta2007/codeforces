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

int n, m, px[N], py[N]; 
int he[N], ne[N*2], ad[N*2]; 

bool v[N]; int f[N], d[N], p[N]; 
vector<int> A[N]; bool g[N]; 

void addE(int x, int y) {
    static int t = 0; 
    ++t, ne[t] = he[x], he[x] = t, ad[t] = y; 
    ++t, ne[t] = he[y], he[y] = t, ad[t] = x; 
}

void ff(int x) {
    v[x] = 1; 
    if (f[x] != 0) {
        A[x].pb(f[x]); 
    }
    for (int p = he[x]; p; p = ne[p]) 
        if (v[ad[p]] && ad[p] != f[x]) 
            A[x].pb(ad[p]); 
    for (int p = he[x]; p; p = ne[p]) 
        if (!v[ad[p]]) {
            f[ad[p]] = x; 
            d[ad[p]] = d[x] + 1; 
            ff(ad[p]); 
            A[x].pb(ad[p]); 
        }
    reverse(A[x].begin(), A[x].end()); 
}

bool cmp(int x, int y) {
    return d[x] > d[y]; 
}

int main() {
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < m; i ++) {
        scanf("%d%d", px+i, py+i); 
        addE(px[i], py[i]); 
    }
    if (m&1) {
        puts ("No solution"); 
        return 0; 
    }
    ff(1); 
    for (int i = 0; i < n; i ++) p[i] = i+1; 
    sort(p, p+n, cmp); 
    for (int i = 0; i < n; i ++) {
        int x = p[i]; 
        vector<int> B;
        for (vector<int>::iterator j = A[x].begin(); j != A[x].end(); j ++) 
            if (!g[*j]) B.pb(*j); 
        int w = (int) B.size(); 
        if (w&1) g[x] = 0; 
        else g[x] = 1; 
        for (int j = 0; j+1<w; j += 2) {
            if (d[B[j]] > d[x]) g[B[j]] = 1; 
            if (d[B[j+1]] > d[x]) g[B[j+1]] = 1; 
            printf("%d %d %d\n", B[j], x, B[j+1]); 
        }
    }
    return 0; 
}