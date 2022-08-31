#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 300111;
struct Node {
    int cnt;
    int e[2];
} bor[N*31];
int bs = 0;
int newNode() {
    bor[bs].cnt = 0;
    bor[bs].e[0] = -1;
    bor[bs].e[1] = -1;
    return bs++;
}

int doIt(int a) {
    int x = 0;
    int v = 0;
    for (int i = 29; i >= 0; --i) {
        int j = ((a & (1 << i)) ? 1 : 0);
        int e = bor[v].e[j];
        if (e == -1 || bor[e].cnt == 0) {
            j ^= 1;
            e = bor[v].e[j];
        }
        x |= (j << i);
        --bor[v].cnt;
        v = e;
    }
    --bor[v].cnt;
    return x ^ a;
}

void addInt(int x) {
    int v = 0;
    ++bor[v].cnt;
    for (int i = 29; i >= 0; --i) {
        int &e = bor[v].e[1 & (x >> i)];
        if (e == -1)
            e = newNode();
        v = e;
        ++bor[v].cnt;
    }
}

int main() {
    newNode();
    int n;
    scanf("%d", &n);
    static int a[N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        addInt(p);
    }

    for (int i = 0; i < n; ++i) {
        cout << doIt(a[i]) << " ";
    }
    cout << "\n";

    return 0;
}