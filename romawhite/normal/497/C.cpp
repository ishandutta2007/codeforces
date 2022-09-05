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
#define eps 1e-9
typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 7000;
const int BASE = 1000000000;

struct S
{
    int type;
    int l;
    int r;
    int k;
    int id;
    S() {}
    S(int t, int _l, int _r, int _k, int _id):type(t), l(_l), r(_r), k(_k), id(_id) {}
    bool operator<(const S & s)const
    {
        if (l < s.l) return 1;
        if (l > s.l) return 0;
        if (type < s.type) return 1;
        if (type > s.type) return 0;
        return id < s.id;
    }
};

set<pair<pair<int,int> , int> > s;

int main()
{
    #ifndef ONLINE_JUDGE
      //freopen("in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<S> A;
    vector<int> res(n);
    FOR(i,0,n)
    {
        int a,b;
        scanf("%d%d" , &a , &b);
        A.push_back(S(1,a,b,0,i));
    }

    int m;
    cin >> m;
    FOR(i,0,m)
    {
        int a,b,k;
        scanf("%d%d%d" , &a , &b , &k);
        A.push_back(S(0,a,b,k,i + n));
    }

    sort(ALL(A));

    FOR(i,0,n + m)
    {
        if (A[i].type == 0)
        {
            s.insert(MP(MP(A[i].r,A[i].k),A[i].id));
        }
        else
        {
            set<pair<pair<int,int> , int> >::iterator it = s.lower_bound(MP(MP(A[i].r, -1), -1));
            if (it == s.end())
            {
                cout << "NO\n";
                return 0;
            }
            int r = it->first.first;
            int k = it->first.second;
            int id = it->second;

            res[A[i].id] = id + 1 - n;
            s.erase(it);
            if (k > 1)
            {
                s.insert(MP(MP(r,k - 1), id));
            }
        }
    }

    cout << "YES\n";
    FOR(i,0,res.size())
    {
        printf("%d ", res[i]);
    }

    return 0;
}