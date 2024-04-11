#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const ll MOD = 1e9 + 7;

int N; // tot length of str
int len[3]; // length of each str
string s;

ll ps[MAXN];
ll mult[MAXN];

void hinit()
{
    ps[0] = 0;
    for (int i = 0; i < N; i++)
        ps[i+1] = MOD * ps[i] + s[i];
    mult[0] = 1;
    for (int i = 0; i < MAXN - 1; i++)
        mult[i+1] = mult[i] * MOD;
}

ll hash (int start, int end) // 0 <= start < end <= N
{
    return ps[end] - ps[start] * mult[end-start];
}

bool check (int left, int right, int len)
{
    return hash (left, left + len) == hash (right, right + len);
}

int type (int x) // 0 1 or 2 depending on string loc
{
    if (x < len[0]) return 0;
    x -= len[0];
    if (x < len[1]) return 1;
    return 2;
}

int nleft (int x)
{
    int ctot = 0;
    for (int i = 0; i <= type (x); i++)
        ctot += len[i];
    
    //cout << ctot - x << "\n";
    return ctot - x;
}

inline bool cmp (int left, int right)
{
    int t = min (nleft (left), nleft (right));
    if (check (left, right, t))
        return nleft (left) < nleft (right);
    
    int lo = 0, hi = t;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (!check (left, right, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return s[left+lo-1] < s[right+lo-1];
}

inline int floc (int left, int right) // first point where stuff happens
{
    int t = min (nleft (left), nleft (right));
    
    if (check (left, right, t))
    {
        return t + 1;
    }
    
    int lo = 0, hi = t;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (!check (left, right, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    
    return lo;
}

int ord[MAXN];
int diff[MAXN];
int psum[MAXN][3];
vector <int> cloc[MAXN];

ll res;
int next[MAXN], prev[MAXN];

void join (int x)
{
    int right = x + 1, left = prev[right];
    int fright = next[right];
    
    next[left] = fright;
    prev[fright] = left;
    
    ll a[3], b[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = psum[right][i] - psum[left][i];
        b[i] = psum[fright][i] - psum[right][i];
    }
    
    //cout << x << " " << left <<  right << fright << "\n";
    
    res -= a[0] * a[1] * a[2];
    res %= MOD;
    res -= b[0] * b[1] * b[2];
    res %= MOD;
    res += (a[0] + b[0]) * (a[1] + b[1]) * (a[2] + b[2]);
    res %= MOD;
    res += MOD;
    res %= MOD;
}


string a, b, c;
ll ans[MAXN];

int main()
{
    cin >> a >> b >> c;
    len[0] = a.length(), len[1] = b.length(), len[2] = c.length();
    s = a + b + c;
    N = len[0] + len[1] + len[2];

    hinit();
    for (int i = 0; i < N; i++)
        ord[i] = i;
    sort (ord, ord + N, cmp);
    for (int i = 0; i < N - 1; i++)
    {
        diff[i] = floc (ord[i], ord[i+1]);
        cloc[diff[i]].push_back (i);
    }
    
    prev[0] = N + 1;
    next[N + 1] = 0;
    prev[N] = N - 1;
    next[N - 1] = N;
    for (int i = 0; i < N - 1; i++)
    {
        next[i] = i + 1;
        prev[i + 1] = i;
    }
    
    for (int i = 0; i < 3; i++)
        psum[0][i] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            psum[i+1][j] = psum[i][j];
        psum[i+1][type (ord[i])]++;
    }
    
   // for (int i = 0; i < N; i++)
   //     cout << ord[i] << diff[i] << type (ord[i]) << "\n";
    
    res = 0;
    
    for (int i = N; i >= 1; i--)
    {
        ans[i] = res;
        for (int j = 0; j < cloc[i].size(); j++)
            join (cloc[i][j]);
    }
    
    for (int i = 1; i <= min (len[0], min (len[1], len[2])); i++)
    {
        cout << ans[i];
        if (i < N) cout << " ";
    }
    cout << "\n";
    
    //system ("Pause");
    return 0;
}