#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

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

const int N = 100111;

int n;
int s2i(string const& s) {
    if (s[0] == '0')
        return -1;
    int x = 0;
    for (char c : s) {
        if (c < '0' || c > '9')
            return -1;
        x *= 10;
        x += c - '0';
    }
    if (x <= 0 || x > n)
        return -1;
    return x;
}

struct File {
    string name;
    bool st;
};
vector < File > files;
int e;
set < int > free1, free2;
set < int > f12, f21, f01, f02;

vector < pair < string, string > > ans;
void fmove(int v, string const& nf) {
    File & file = files[v];
    ans.emplace_back(file.name, nf);
    int x = s2i(file.name);
    if (x == -1) {
        (file.st ? f01 : f02).erase(v);
    } else {
        if (x <= e) {
            free1.insert(x);
            if (!file.st)
                f12.erase(v);
        } else {
            free2.insert(x);
            if (file.st)
                f21.erase(v);
        }
    }
    file.name = nf;
    x = s2i(nf);
    if (x == -1) {
        (file.st ? f01 : f02).insert(v);
    } else {
        if (x <= e) {
            free1.erase(x);
            if (!file.st)
                f12.insert(v);
        } else {
            free2.erase(x);
            if (file.st)
                f21.insert(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    files.resize(n);
    for (int i = 0; i < n; ++i) {
        char ss[10];
        int x;
        scanf("%s%d", ss, &x);
        files[i].name = ss;
        files[i].st = x;
        e += x;
    }

    for (int i = 1; i <= e; ++i)
        free1.insert(i);
    for (int i = e+1; i <= n; ++i)
        free2.insert(i);
    for (int i = 0; i < n; ++i) {
        int x = s2i(files[i].name);
        if (x == -1) {
            (files[i].st ? f01 : f02).insert(i);
        } else {
            (x <= e ? free1 : free2).erase(x);
            if (x <= e && !files[i].st)
                f12.insert(i);
            else if (x > e && files[i].st)
                f21.insert(i);
        }
    }


    if (sz(f01) + sz(f02) == 0 && sz(f12) != 0) {
        int v = *f12.begin();
        fmove(v, "qwe");
    }

    while (true) {
        if (sz(f12) > 0 && sz(free2) > 0) {
            int v = *f12.begin();
            int p = *free2.begin();
            fmove(v, to_string(p));
        } else if (sz(f21) > 0 && sz(free1) > 0) {
            int v = *f21.begin();
            int p = *free1.begin();
            fmove(v, to_string(p));
        } else
            break;
    }

    while (sz(f01) > 0) {
        int v = *f01.begin();
        int p = *free1.begin();
        fmove(v, to_string(p));
    }
    while (sz(f02) > 0) {
        int v = *f02.begin();
        int p = *free2.begin();
        fmove(v, to_string(p));
    }

    cout << sz(ans) << "\n";
    for (auto const& x : ans)
        cout << "move " << x.X << " " << x.Y << "\n";

    return 0;
}