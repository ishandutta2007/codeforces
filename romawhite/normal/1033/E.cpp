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
const int MAX = 607;
const double PI = acos(-1.);
const double EPS = 1e-8;

int E[MAX][MAX];
int cnt = 0;


int ask(VI a)
{
    if (SZ(a) <= 1) return 0;
    
    ++ cnt;

    
    cout << "? " << SZ(a) << endl;
    FOR(i,0,SZ(a))
    {
        cout << a[i] + 1 << ' ';
    }
    cout << endl;
    cout.flush();
    
    int val = 0;
    cin >> val;
    
    if (val == -1) throw -1;
    
//    FOR(i,0,SZ(a))
//        FOR(j,i + 1, SZ(a))
//    {
//        val += E[a[i]][a[j]];
//    }
    return val;
}

VI G[MAX];

int C[MAX];
int P[MAX];

void dfs(int v, int p, int c)
{
    C[v] = c;
    P[v] = p;
    
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i];
        if (to == p) continue;
        dfs(to, v, c ^ 1);
    }
    
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
//    int n , m;
//
//    n = 600;
//
//    FOR(i,1,n)
//    E[0][i] = E[i][0] = 1;
    
//    cin >> n >> m;
    
//    FOR(i,0,m)
//    {
//        int a , b;
//        cin >> a >> b;
//        --a;--b;
//        E[a][b] = E[b][a] = 1;
//    }

    
//
    int n;
    cin >> n;
    
    VI A;
    VI B;
    A.push_back(0);
    FOR(i,1,n)
    {
        B.push_back(i);
    }
    
    FOR(it,0,n - 1)
    {
        int L = 0;
        int R = SZ(B) - 1;
        
        int edgesA = ask(A);
        
        while (R != L)
        {
            int m = (L + R) / 2;
            VI X;
            FOR(t,L, m + 1)
                X.push_back(B[t]);
            
            int edgesX = ask(X);
            
            FOR(t,0,SZ(A))
            X.push_back(A[t]);
            int edgesAX = ask(X);
            
            if (edgesAX == edgesA + edgesX)
            {
                L = m + 1;
            }
            else
            {
                R = m;
            }
        }
        
        int idB = L;
        
        L = 0;
        R = SZ(A) - 1;
        
        while (R != L)
        {
            int m = (L + R) / 2;
            VI X;
            FOR(t,L, m + 1)
                X.push_back(A[t]);
            
            int edgesX = ask(X);
            
            X.push_back(B[idB]);
            int edgesBX = ask(X);
            
            if (edgesBX == edgesX)
            {
                L = m + 1;
            }
            else
            {
                R = m;
            }
        }
        
        int idA = L;
        
        int v = A[idA];
        int to = B[idB];
        
        G[v].push_back(to);
        G[to].push_back(v);
        
        
        swap(B[idB] , B.back());
        B.pop_back();
        A.push_back(to);
    }
    
    dfs(0, -1, 0);
    
    A.clear();
    B.clear();
    
    FOR(i,0,n)
    {
        if (C[i] == 0)
            A.push_back(i);
        else
            B.push_back(i);
    }
    
    
    if (ask(A) == 0 && ask(B) == 0)
    {
        cout << "Y " << SZ(A) << endl;
        FOR(i,0,SZ(A))
        {
            cout << A[i] + 1 << ' ';
        }
        cout << endl;
        cout.flush();
        
//        cerr <<  "CNT  " << cnt << endl;
        
        return 0;
    }
    
    
    if (ask(B) != 0)
    {
        swap(A , B);
    }
    
    
    int a = -1;
    int b = -1;
    
    
    while (true)
    {
        if (SZ(A) == 2)
        {
            a = A[0];
            b = A[1];
            break;
        }
        
        int last = A.back();
        A.pop_back();
        
        if (ask(A) == 0)
        {
            a = last;
            
            FOR(i,0,SZ(A))
            {
                VI X;
                X.push_back(a);
                X.push_back(A[i]);
                if (ask(X) != 0)
                {
                    b = A[i];
                    break;
                }
            }
            
            break;
        }
    }
    
    
    
    dfs(a, -1, 0);
    
    VI path;
    
    while (b != a)
    {
        path.push_back(b);
        b = P[b];
    }
    path.push_back(a);
    reverse(ALL(path));
    
    cout << "N " << SZ(path) << endl;
    FOR(i,0,SZ(path))
    {
        cout << path[i] + 1 << ' ';
    }
    cout << endl;
    
//    cerr << "CNT " << cnt << endl;
    
    return 0;
}