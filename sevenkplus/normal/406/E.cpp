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
#define INF 1000000007

int n, m, s[N], w[N]; 

struct AS {
    ll S, T; 
    
    AS (ll _S, ll _T):S(_S), T(_T) {}
    
    AS operator + (const AS&a) {
        if (a.T == 0) return *this;
        if (T == 0) return a; 
        if (S > a.S) return *this; 
        if (S < a.S) return a; 
        return AS(S, T+a.T); 
    }
}; 

struct T {
    int l, r; 
    int mi, ma, s; 
    T *cl, *cr; 
    
    T (int _l, int _r):l(_l), r(_r) {
        mi = INF, ma = -INF; s = 0; 
        cl = cr = NULL; 
    } 
    
    void add (int x) {
        if (l == r) {
            mi = ma = x; s ++; 
            return; 
        }
        int mid = (l+r)/2; 
        if (cl == NULL) {
            cl = new T(l, mid); 
            cr = new T(mid+1, r); 
        }
        if (x <= mid) cl -> add(x); 
        else cr -> add(x); 
        mi = min(cl->mi, cr->mi); 
        ma = max(cl->ma, cr->ma); 
        s = cl->s + cr->s; 
    }
    
    int ami (int L, int R) {
        if (mi == INF) return mi; 
        if (L <= l && r <= R) return mi; 
        int mid = (l+r)/2;
        int S = INF; 
        if (L <= mid) S = min(S, cl->ami(L, R)); 
        if (mid+1 <= R) S = min(S, cr->ami(L, R)); 
        return S; 
    }
    
    int ama (int L, int R) {
        if (ma == -INF) return ma; 
        if (L <= l && r <= R) return ma; 
        int mid = (l+r)/2;
        int S = -INF;
        if (L <= mid) S = max(S, cl->ama(L, R)); 
        if (mid+1 <= R) S = max(S, cr->ama(L, R));
        return S; 
    }
    
    int asi (int L, int R) {
        if (s == 0) return s; 
        if (L <= l && r <= R) return s; 
        int mid = (l+r)/2;
        int S = 0; 
        if (L <= mid) S += cl->asi(L, R); 
        if (mid+1 <= R) S += cr->asi(L, R);
        return S; 
    }
}; 

AS ff() {
    T* T1 = new T(0, n); 
    int S1 = 0; 
    for (int i = 0; i < m; i ++) 
        if (s[i] == 1) {
            T1->add(w[i]); 
            S1 ++; 
        }
    if (S1 <= 1) return AS(-1, 0); 
    int ma = T1->ama(0, n); 
    int mi = T1->ami(0, n); 
    int cmi = T1->asi(mi, mi);
    int cma = T1->asi(ma, ma); 
    AS S(-1, 0); 
    if (ma != mi) {
        S = AS((ma-mi)*2LL, (ll)cmi*cma*(S1-cmi-cma) + (ll)cmi*(cmi-1)/2*cma + (ll)cma*(cma-1)/2*cmi); 
    } else {
        S = AS(0, (ll)cmi*(cmi-1)*(cmi-2)/6); 
    }
    T* T0 = new T(0, n); 
    for (int i = 0; i < m; i ++) 
        if (s[i] == 0) T0 -> add(w[i]); 
    for (int i = 0; i < m; i ++) 
        if (s[i] == 1) {
            if (w[i] <= n && w[i] > mi) {
                int ma = T0 -> ama(0, n-w[i]); 
                if (ma != -INF) {
                    int mas = T0 -> asi(ma, ma); 
                    S = S + AS((w[i]+ma)*2LL, (ll)T1->asi(0, w[i]-1)*mas); 
                }
            }
            if (w[i] >= 0 && w[i] < ma) {
                int mi = T0 -> ami(n-w[i], n); 
                if (mi != INF) {
                    int mis = T0 -> asi(mi, mi); 
                    S = S + AS((n-w[i]+n-mi)*2LL, (ll)T1->asi(w[i]+1, n)*mis); 
                }
            }
        }
    for (int i = 0; i < m; i ++)
        if (s[i] == 0) {
            if (w[i] > 0 && w[i] < n) 
                S = S + AS(n*2LL, (ll)T1->asi(0, n-w[i]-1)*T1->asi(n-w[i]+1, n)); 
        }
    set<int> v; 
    for (int i = 0; i < m; i ++) 
        if (s[i] == 1) {
            int u = w[i]; 
            if (v.find(u) != v.end()) continue;
            v.insert(u); 
            int su = T1 -> asi(u, u); 
            if (su == 1) continue; 
            if (u < n) {
                int ma = T0 -> ama(0, n-u-1); 
                if (ma != -INF) {
                    int mas = T0 -> asi(ma, ma); 
                    S = S + AS((u+ma)*2LL, (ll)su*(su-1)/2*mas); 
                }
            }
            if (u >= 0) {
                int mi = T0 -> ami(n-u, n); 
                if (mi != INF) {
                    int mis = T0 -> asi(mi, mi); 
                    S = S + AS((n-u+n-mi)*2LL, (ll)su*(su-1)/2*mis); 
                }
            }
        }
    return S; 
}

int main() {
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < m; i ++) {
        scanf("%d%d", s+i, w+i); 
        if (s[i] == 1) {
            // L
            // do nothing
        } else
        if (s[i] == 0) {
            w[i] = n-w[i]; 
        }
    }
    
    AS S(-1,0);
    S = S + ff(); 
    for (int i = 0; i < m; i ++) {
        s[i] = 1-s[i]; 
    }
    S = S + ff(); 
    cout << S.T << endl; 
    return 0; 
}