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
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979


typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000000000;
const int BASE = 243*27;
const double EPS = 1e-7;
const int MAX = 32000000;

bool R[10007];

int P[MAX];

Int bpow(Int a, Int k, int mod)
{
    a %= mod;
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        k /= 2;
    }
    return res;
}

Int d[100007];

void dijkstra(vector<Int> p)
{
    int a = p[0];
    
    FOR(i,0,a)
    {
        d[i] = 1LL * INF * INF;
    }
    d[0] = 0;
    
    set<pair<Int, int> > S;
    S.insert(MP(0,0));
    
    while (SZ(S))
    {
        pair<Int, int> pr = *S.begin();
        S.erase(S.begin());
        int v = pr.second;
        
        FOR(i,1,SZ(p))
        {
            int to = (v + p[i]) % a;
            if (d[to] > d[v] + p[i])
            {
                S.erase(MP(d[to] , to));
                d[to] = d[v] + p[i];
                S.insert(MP(d[to] , to));
            }
                 
        }
        
    }
    
    
}

int main()
{
    //freopen("in.txt", "r", stdin);
    
    for(int i = 2; i * i < MAX; ++i)
        if (!P[i])
            for(int j = i * i; j < MAX; j += i)
                P[j] = 1;
    
    VI pr;
    FOR(i,2,MAX)
        if (!P[i])
            pr.push_back(i);
    
    
    int t;
    cin >> t;
    vector<pair<pair<Int,Int> , int> > A;
    
    FOR(i,0,t)
    {
        Int n , k;
        cin >> n >> k;
        A.push_back(MP(MP(k,n) , i));
    }
    
    sort(ALL(A));
    
    int pos = 0;
    while (pos < t)
    {
        int add = 1;
        while (pos + add < SZ(A) && A[pos + add].first.first == A[pos].first.first) ++ add;
        
        Int k = A[pos].first.first;
        vector<Int> p;
        
        FOR(i,0,SZ(pr))
        {
            if ((Int)pr[i] * pr[i] > k) break;
            if (k % pr[i] == 0)
            {
                p.push_back(pr[i]);
                while (k % pr[i] == 0) k /= pr[i];
            }
        }
        if (k != 1) p.push_back(k);
        sort(ALL(p));
        
        
        if (p.size() == 0)
        {
            pos += add;
            continue;
        }
        
        if (p.size() == 1)
        {
            FOR(i,pos, pos + add)
            {
                Int n = A[i].first.second;
                if (n % p[0] == 0)
                {
                    R[A[i].second] = true;
                }
            }
            pos += add;
            continue;
        }
        
        if (p.size() == 2)
        {
            FOR(i,pos , pos + add)
            {
                Int n = A[i].first.second;
                Int y = (n % p[0]) * bpow(p[1] , p[0] - 2, p[0]) % p[0];
                if (n >= y * p[1])
                {
                    R[A[i].second] = true;
                }
            }
            pos += add;
            continue;
        }
        
        dijkstra(p);
        
        FOR(i,pos , pos + add)
        {
            Int n = A[i].first.second;
            if (d[n % p[0]] <= n)
            {
                R[A[i].second] = true;
            }
        }
        pos += add;
        
        
    }
    
    FOR(i,0,t)
    {
        if (R[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    
    
    
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;

    return 0;
}