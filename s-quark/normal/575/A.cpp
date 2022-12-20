#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 51234;

int P;

typedef int (*mat)[2];

void mov(mat a, mat b){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = b[i][j];
}

void mul(mat a, mat b, mat c){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = 0;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                a[i][k] = (a[i][k] + (ll)b[i][j] * c[j][k]) % P;
}

int s[MAXN];

int a[MAXN*2][2][2];

pair<ll, int> q[MAXN];

void make(mat a, int si, int si1){
    a[0][0] = 0;
    a[0][1] = si;
    a[1][0] = 1;
    a[1][1] = si1;
}

void make(mat a, int i){
    a[0][0] = 0;
    a[0][1] = s[i];
    a[1][0] = 1;
    a[1][1] = s[i+1];
}

mat build(int l, int r){
    mat p;
    if(r-l == 1)
        p = a[l+r];
    else
        p = a[(l+r)/2*2];

    if(r-l == 1){
        make(p, l);
    }
    else{
        int mid = (l+r)/2;
        mul(p, build(l, mid), build(mid, r));
    }
    return p;
}

bool cmp(const pair<ll, int> &a, const pair<ll, int> &b){
    return a.fi < b.fi;
}

int ans[2][2];
int t[2][2], t2[2][2], t3[2][2];
int n;
ll cur;

//0 for default
void step(int si, int si1){
    if(si == 0)
        si = s[(int)(cur%n)];
    if(si1 == 0)
        si1 = s[(int)((cur+1)%n)];
    make(t, si, si1);
    mul(t2, ans, t);
    mov(ans, t2);
    cur++;
}

void pow(ll k){
    t2[0][0] = t2[1][1] = 1;
    t2[1][0] = t2[0][1] = 0;
    for(int i = 60; i >= 0; i--){
        if(1LL<<i & k){
            mul(t3, t2, t2);
            mul(t2, t, t3);
        }
        else{
            mul(t3, t2, t2);
            mov(t2, t3);
        }
    }
    mov(t, t2);
}

void get(mat t, int l, int r, int L, int R){
    mat p;
    if(r-l == 1)
        p = a[l+r];
    else
        p = a[(l+r)/2*2];

    if(L==l && R==r){
        mov(t, p);
        return;
    }

    int mid = (l+r)/2;
    if(R <= mid)
        get(t, l, mid, L, R);
    else if(L >= mid)
        get(t, mid, r, L, R);
//  else if(l == L){
//      get(t2, l, mid, L, mid);
//      get(t, mid, r, mid, R);
//      mul(t3, t2, t);
//      mov(t, t3);
//  }
//  else if(r == R){
//      get(t, l, mid, L, mid);
//      get(t2, mid, r, mid, R);
//      mul(t3, t, t2);
//      mov(t, t3);
//  }
    else{
        int tl[2][2], tr[2][2];
        get(tl, l, mid, L, mid);
        get(tr, mid, r, mid, R);
        mul(t, tl, tr);
    }
}

void get(int l, int r){
    get(t, 0, n, l, r);
}

void add(int l, int r){
    if(l == r)
        return;
    get(l, r);
    mul(t2, ans, t);
    mov(ans, t2);
    cur += r-l;
}

void upto(ll K){
    if(cur/n == K/n){
        add(cur%n, K%n);
    }
    else{
        add(cur%n, n);

        get(0, n);
        pow((K-cur)/n);
        mul(t2, ans, t);
        mov(ans, t2);
        cur += (K-cur)/n*n;

        add(0, K%n);
    }
}

int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll K;
    int m;
    int i, j, k;

    scanf("%I64d%d%d", &K, &P, &n);
    for(i = 0; i < n; i++)
        scanf("%d", &s[i]);
    s[n] = s[0];
    scanf("%d", &m);
    for(i = 0; i < m; i++)
        scanf("%I64d%d", &q[i].fi, &q[i].se);

    build(0, n);

    sort(q, q+m, cmp);
    ans[0][0] = ans[1][1] = 1;
    ans[0][1] = ans[1][0] = 0;
    cur = 0;
    i = 0;
    while(cur < K){
        if(i < m && K > q[i].fi-1){
            upto(q[i].fi-1);
            step(0, q[i].se);
            while(i+1 < m && q[i+1].fi == q[i].fi+1 && cur < K){
                step(q[i].se, q[i+1].se);
                i++;
            }
            if(cur == K)
                break;
            step(q[i].se, 0);
            i++;
        }
        else{
            upto(K);
        }
    }

    printf("%d\n", ans[1][0]%P);

    return 0;
}