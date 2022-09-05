#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL*INF*INF;
const int MAX = 307;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 1000000007;

string f(string s)
{
    string s2 = s;
    reverse(ALL(s2));
    return min(s , s2);
}

int main()
{
    //        freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    string res = "";
    res += s[0];
    
    FOR(i,1,SZ(s))
    {
        if (f(s[i] + res) < f(res + s[i]))
        {
            reverse(ALL(res));
            cout << 1 << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
        res += s[i];
//        cout << res << endl;
    }
    
    string res2 = res;
    reverse(ALL(res2));
    if (res2 < res)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}