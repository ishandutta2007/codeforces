#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define do(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i < (k); i ++)
#define dec(i, j, k) for(int i = j; i >= (k); i --)
#define mfil(x, k) memset(x, k, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y, true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y, true) : false; }
struct __init { __init()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cout.precision(16); cout << fixed;
	srand(time(0) ^ ul(new char));
} } static __init__;
/* default code ends here */

const int maxn = 1e6 + 10;
int n, m;

int xx, yy;
struct node
{
    int u, v, w;
    void input()
    {
        cin >> u >> v >> w;
    }
    friend bool operator < (node a, node b)
    {
        return a.w < b.w;
    }
} a[maxn];

int fa[maxn];
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
int cw;
void merge(int x, int y)
{
    int f1 = getfa(x), f2 = getfa(y);
    if(f1 != f2)
        fa[f1] = f2;
    if(getfa(xx) == getfa(yy))
    {
        cout << cw << endl;
        exit(0);
    }
}

int main()
{
	cin >> n >> m;
    cin >> xx >> yy;
    int tmp;
    cin >> tmp;
    m --;
    do(i, 1, m)
        a[i].input();
    sort(a + 1, a + m + 1);
    do(i, 1, n)
        fa[i] = i;
    do(i, 1, m)
    {
        cw = a[i].w;
        merge(a[i].u, a[i].v);
    }
    cout << int(1e9) << '\n';
	return 0;
}