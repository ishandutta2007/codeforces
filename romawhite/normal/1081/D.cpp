#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 100007;
const int MOD = 998244353;
const double Pi = acos(-1.);

int p[MAX];
int c[MAX];

int get(int x)
{   
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
}

int Union(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a == b)
        return -1;
    if (rand() % 2) swap(a , b);
    p[b] = a;
    c[a] += c[b];
    return c[a];
}

int main()
{
    int n , m , k;
    cin >> n >> m >> k;

    FOR(i,0,k)
    {   
        int x;
        scanf("%d" , &x);
        --x;
        c[x] = 1;
    }

    vector<pair<int, PII> > E;
    FOR(i,0,m)
    {   
        int a , b , c;
        scanf("%d%d%d" , &a , &b, &c);
        --a;--b;
        E.push_back(MP(c , MP(a , b)));
    }
    sort(ALL(E));

    FOR(i,0,n)
    {   
        p[i] = i;
    }

    int res;

    FOR(i,0,m)
    {   
        int a = E[i].second.first;
        int b = E[i].second.second;
        int c = Union(a , b);
        if (c == k)
        {
            res = E[i].first;
            break;
        }
    }

    FOR(i,0,k)
    {   
        printf("%d " , res);
    }
    cout << endl;


    return 0;
}