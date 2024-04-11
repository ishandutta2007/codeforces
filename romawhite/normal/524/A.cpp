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
#include <complex>
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

const int INF = 1000000000;
const int MAX = 200000;
const int MAX2 = 2000;
const int BASE = 1000000000;

set<pair<int,int> > E;
map<int, int > M;
vector<int> A;

int main()
{
    //freopen("in.txt", "r", stdin);

    int m , K;
    cin >> m >> K;

    FOR(i,0,m)
    {
        int a , b;
        cin >> a >> b;
        E.insert(MP(a , b));
        E.insert(MP(b , a));
        M[a]++;
        M[b]++;
        A.push_back(a);
        A.push_back(b);
    }
    sort(ALL(A));
    A.resize(unique(ALL(A)) - A.begin());

    FOR(i,0,A.size())
    {
        vector<int> res;
        FOR(j,0,A.size())
        {
            if (i == j) continue;
            if (E.find(MP(A[i] , A[j])) != E.end()) continue;
            int cnt = 0;
            FOR(k,0,A.size())
            {
                if (i == k || j == k) continue;
                if (E.find(MP(A[i] , A[k])) != E.end() && E.find(MP(A[j] , A[k])) != E.end())
                {
                    ++cnt;
                }
            }
            if (cnt * 100 >= M[A[i]] * K)
            {
                res.push_back(A[j]);
            }
        }
        cout << A[i] << ": ";
        cout << res.size();
        FOR(j,0,res.size())
        {
            cout << ' ' << res[j];
        }
        cout << endl;
    }

    return 0;
}