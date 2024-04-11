#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000;
const LL LINF = INF * (LL) INF;


const int MAX = 2007;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int MOD = 998244353;


VI G[MAX];
bool C[MAX];
int p[MAX];

void dfs(int v, int par)
{
    p[v] = par;
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i];
        if (to == par) continue;
        dfs(to, v);
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
    //    ios::sync_with_stdio(false); cin.tie(0);
    
    int t;
    cin >> t;
    
    FOR(tt,0,t)
    {
        int n;
        cin >> n;
        
        FOR(i,0,n)
        {
            G[i].clear();
        }
        
        FOR(i,0,n - 1)
        {
            int a , b;
            scanf("%d%d" , &a , &b);
            --a;--b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        FILL(C,0);
        
        int k1;
        cin >> k1;
        VI A(k1);
        FOR(i,0,k1)
        {
            scanf("%d" , &A[i]);
            --A[i];
            C[A[i]] = 1;
        }
        int k2;
        cin >> k2;
        VI B(k2);
        FOR(i,0,k2)
        {
            scanf("%d" , &B[i]);
            --B[i];
        }
        
        int root = A[0];
        dfs(root, -1);
        
        
        cout << "A " << root + 1 << endl;
        int v;
        cin >> v;
        -- v;
        
        bool ok = false;
        FOR(i,0,SZ(B))
        {
            if (B[i] == v)
            {
                ok = true;
                break;
            }
        }
        
        if (ok)
        {
            cout << "C " << root + 1 << endl;
            continue;
        }
        
        cout << "B " << B[0] + 1 << endl;
        cin >> v;
        -- v;
        
        while (!C[v])
        {
            v = p[v];
        }
        
        cout << "A " << v + 1 << endl;
        int u;
        cin >> u;
        --u;
        ok = false;
        FOR(i,0,SZ(B))
        {
            if (B[i] == u)
            {
                ok = true;
                break;
            }
        }
        
        if (ok)
        {
            cout << "C " << v + 1 << endl;
            continue;
        }
        
        cout << "C " << -1 << endl;
        
    }
    
    
    
    
    
    return 0;
}