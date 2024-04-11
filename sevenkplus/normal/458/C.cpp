#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 10010
map<int,multiset<int> > A;
int f[N*4],g[N*4];
int n; 

void upd(int p, int l, int r, int x, int y) {
    if (l == r-1) {
        f[p] += y;
        g[p] += x*y;
        return;
    }
    int mid = (l+r)/2;
    if (x < mid) upd(p*2+1,l,mid,x,y);
    else upd(p*2+2,mid,r,x,y);
    f[p] = f[p*2+1]+f[p*2+2];
    g[p] = g[p*2+1]+g[p*2+2];
}

int ask(int p, int l, int r, int k) {
    if (k == 0) return 0;
    if (k == f[p]) return g[p];
    if (l == r-1) return g[p]/f[p]*k;
    int mid = (l+r)/2;
    if (f[p*2+1] >= k) return ask(p*2+1,l,mid,k);
    else return g[p*2+1]+ask(p*2+2,mid,r,k-f[p*2+1]);
}

int p[100010],L,s[100010];
bool cmp(int x, int y) {
    return s[x] > s[y];
}

typedef map<int,multiset<int> >::iterator mit;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        int x, y;
        scanf("%d%d",&x,&y);
        if (x != 0) {A[x].insert(y);}
        upd(0,0,N,y,1);
    }
    
    for (mit i = A.begin(); i != A.end(); i ++) {
        p[L++] = i->fi;
        s[i->fi] = (int)i->se.size();
    }
    sort(p,p+L,cmp);
    
    int j = 0;
    int T = 0, TS = 0;
    int S = 1e9;
    
    for (int i = n; i >= 1; i --) {
        while (j < L && s[p[j]] >= i) j ++;
        for (int k = 0; k < j; k ++) {
            int s = *A[p[k]].begin();
            T ++;
            TS += s;
            upd(0,0,N,s,-1);
            A[p[k]].erase(A[p[k]].begin());
        }
        int U = max(0,i-T);
        int SS = TS;
        if (U > 0) SS += ask(0,0,N,U);
        S = min(S, SS);
    }
    cout << S << endl;
    return 0;
}