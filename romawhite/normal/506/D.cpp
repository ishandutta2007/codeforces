#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
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

const int INF = 1000100000;
const int MAX = 100007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

map<int,int> P[MAX];

int get_set(int index , int v)
{
    if (!P[index].count(v) || P[index][v] == v) return P[index][v] = v;
    return P[index][v] = get_set(index, P[index][v]);
}

void union_sets(int index, int a , int b)
{
    a = get_set(index, a);
    b = get_set(index, b);
    if (a != b)
    {
        if (rand() % 2)
        {
            swap(a , b);
        }
        P[index][b] = a;
    }
}

vector<pair<int,int> > A[MAX];

map<pair<int,int> , int> M;

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n, m;
    cin >> n >> m;
    FOR(i,0,m)
    {
        int a , b , c;
        scanf("%d%d%d" , &a , &b , &c);
        --a;--b;--c;
        union_sets(c , a , b);
    }

    FOR(color, 0, m)
    {
        for(map<int,int>::iterator it = P[color].begin(); it != P[color].end(); ++it)
        {
            A[it->first].push_back(MP(color, it->second));
        }
    }

    FOR(i,0,n)
    {
        FOR(j,0,A[i].size())
        {
            A[i][j].second = get_set(A[i][j].first , i);
        }
    }

    int q;
    cin >> q;
    FOR(i,0,q)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        if (A[a].size() > A[b].size() || (A[a].size() == A[b].size() && a > b))
        {
            swap(a , b);
        }
        if (M.count(MP(a , b)))
        {
            printf("%d\n" , M[MP(a , b)]);
            continue;
        }
        int res = 0;
        FOR(i,0,A[a].size())
        {
            if (binary_search(ALL(A[b]) , A[a][i]))
            {
                ++res;
            }
        }
        M[MP(a , b)] = res;
        printf("%d\n" , res);
    }



    return 0;
}