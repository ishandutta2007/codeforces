#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL * INF*INF;
const int MAX = 507;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 998244353;

Int a[MAX];

Int isSquare(Int x)
{
    Int L = 1;
    Int R = 1.1 * sqrt(1.0 * x);
    
    while (R - L > 1)
    {
        Int X = (L + R) / 2;
        if (X * X > x)
        {
            R = X;
        }
        else
        {
            L = X;
        }
    }
    
    if (L * L == x) return L;
    if (R * R == x) return R;
    return -1;
}

Int isCube(Int x)
{
    Int L = 1;
    Int R = 1.1 * pow(x , 1.0 / 3);
    
    while (R - L > 1)
    {
        Int X = (L + R) / 2;
        if (X * X * X > x)
        {
            R = X;
        }
        else
        {
            L = X;
        }
    }
    
    if (L * L * L == x) return L;
    if (R * R * R == x) return R;
    return -1;
}

Int isForth(Int x)
{
    Int L = 1;
    Int R = 1.1 * pow(x , 1.0 / 4);
    
    while (R - L > 1)
    {
        Int X = (L + R) / 2;
        if (X * X * X * X > x)
        {
            R = X;
        }
        else
        {
            L = X;
        }
    }
    
    if (L * L * L * L == x) return L;
    if (R * R * R * R == x) return R;
    return -1;
}

Int gcd(Int a, Int b)
{
    if (!b) return a;
    return gcd(b , a % b);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    FOR(i,0,n)
    {
        cin >> a[i];
    }
    
    map<Int, int> M;
    
    map<Int, int> HZ;
    
    FOR(i,0,n)
    {
        Int v = isForth(a[i]);
        if (v != -1)
        {
            M[v] += 4;
            continue;
        }
        
        v = isCube(a[i]);
        if (v != -1)
        {
            M[v] += 3;
            continue;
        }
        
        v = isSquare(a[i]);
        if (v != -1)
        {
            M[v] += 2;
            continue;
        }
        
        bool ok = false;
        
        FOR(j,0,n)
        {
            Int g = gcd(a[i] , a[j]);
            if (g > 1 && g < a[i])
            {
                M[g] ++;
                M[a[i] / g] ++;
                ok = true;
                break;
            }
        }
        
        if (!ok)
            HZ[a[i]] ++;
    }
    
    Int res = 1;
    for(auto it = M.begin(); it != M.end(); ++it)
    {
        res *= (it->second + 1);
        res %= MOD;
    }
    
    for(auto it = HZ.begin(); it != HZ.end(); ++it)
    {
        res *= (it->second + 1) * (it->second + 1);
        res %= MOD;
    }
    
    cout << res << endl;
    
    
    return 0;
}