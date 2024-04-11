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
const int MAX = 2048;
const int MAX2 = 1000007;
const int MOD = 1000000007;

int a[40007];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int x;
    cin >> x;
    string s;
    cin >> s;

    

    Int res = 0;

    FOR(i,0,s.size()){
        int sum = 0;
        FOR(j,i,s.size()){
            sum += s[j] - '0';
            a[sum]++;
        }
    }

    FOR(i,0,s.size()){
        int sum = 0;
        FOR(j,i,s.size()){
            sum += s[j] - '0';
            if ((sum == 0 && x == 0)){
                res += 1LL * s.size() * (s.size() + 1) / 2;
            }
            if (sum != 0 &&  x % sum == 0 && x / sum < 40007){
                res += a[x / sum];
            }
        }
    }

    cout << res << endl;

}