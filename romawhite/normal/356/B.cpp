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
#include <fstream>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

#define distance sgfsdfgs

typedef long long Int;
typedef unsigned int uint;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MAX = 128;

Int gcd(Int a,Int b){
    if (b == 0) return a;
    return gcd(b , a % b);
}

int A[1000007][26];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    Int n,m;
    cin >> n >> m;

    string a,b;
    cin >> a >> b;

    int g = gcd(a.size() , b.size());

    Int len = n * a.size();
    Int lcm = 1LL * a.size() * b.size() / g;

    FOR(i,0,b.size()){
        A[i % g][b[i] - 'a']++;
    }

    Int res = 0;

    int cnt = b.size() / g;

    FOR(i,0,a.size()){
        res += cnt - A[i % g][a[i] - 'a'];
    }

    res *= len / lcm;


    cout << res << endl;
    return 0;

}