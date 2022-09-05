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
const int MAX = 300007;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 1000000007;

int x[MAX];
int y[MAX];

Int res[MAX];

int main()
{
//            freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    int n , m;
    cin >> n >> m;
    
    FOR(i,0,n)
    {
        cin >> x[i] >> y[i];
        x[i] *= -1;
        y[i] *= -1;
    }
    
    vector<PII > A;
    
    Int sx = 0;
    Int sy = 0;
    FOR(i,0,n)
    {
        sx += x[i];
        sy += y[i];
        A.push_back(MP(y[i] - x[i] , i) );
    }
    
    sort(ALL(A));
    
    Int cursx = 0;
    Int cursy = 0;
    
    FOR(i,0,SZ(A))
    {
        int id = A[i].second;
        
        res[id] += 1LL * y[id] * i;
        res[id] += cursx;
        
        cursx += x[id];
        cursy += y[id];
        
        res[id] += 1LL * x[id] * (n - 1 - i);
        res[id] += (sy - cursy);
        
    }
    
    FOR(i,0,m)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        
        int score = max(x[a] + y[b] , x[b] + y[a]);
        res[a] -= score;
        res[b] -= score;
        
    }
    
    FOR(i,0,n)
    {
        res[i] *= -1;
        cout << res[i] << ' ';
    }
    cout << endl;
    
    
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}