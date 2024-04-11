#include <bits/stdc++.h>

using namespace std;



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 2005



int n;

char s[N], t[N];

vector<int> v[N];

int p[N], q[N];

int cnt;

int ans[N<<2];



void go(int x) {

    ans[cnt++] = x;

    reverse(p + 1, p + n - x + 1);

    reverse(p + 1, p + n + 1);

}



void func(int x, int y) {

    go(n - y);

    go(y - x);

    go(x);

}



int main() {


    scanf("%d ", &n);

    gets(s + 1), gets(t + 1);

    for (int i = 1; i <= n; i ++) {

        v[t[i]-'a'].push_back(i);

    }

    for (int i = 1; i <= n; i ++) {

        if (v[s[i]-'a'].empty()) {

            return puts("-1"), 0;

        }

        int sz = v[s[i]-'a'].size();

        p[i] = v[s[i]-'a'][sz-1];

        v[s[i]-'a'].pop_back();

    }

    int now = (n + 1) / 2;

    int ps = 0;

    for (int i = 1; i <= n; i ++) if (p[i] == now) ps = i;

    go(n - ps);

    go(n);

    int fg = 1, e = now - 1, f = now + 1;

    for (int i = 2; i <= n; i ++, fg ^= 1) {

        int tgt;

        if (fg) tgt = f ++;

        else tgt = e --;

        int ps = 0;

        for (int j = i; j <= n; j ++) if (p[j] == tgt) ps = j;

        func(i - 1, ps);

    } if (n & 1) go(n);

    printf("%d\n", cnt);

    for (int i = 0; i < cnt; i ++) cout<<ans[i]<<endl;

    return 0;

}