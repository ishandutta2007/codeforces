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
const int MAX = 10007;
const double PI = acos(-1.);
const double EPS = 1e-8;

int sign(int x)
{
    return x > 0;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    int x1,y1;
    cin>> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int x3, y3;
    cin >> x3 >> y3;
    
    if (sign(x2 - x1) == sign(x3 - x1) && sign(y2 - y1) == sign(y3 - y1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
    
    
    return 0;
}