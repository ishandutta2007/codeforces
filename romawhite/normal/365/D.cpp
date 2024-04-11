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

bool dp[500007];

int main()
{
//#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
//#endif
    int n,d;
    cin >> n >> d;
    dp[0] = 1;
    FOR(i,0,n){
        int x;
        cin >> x;
        RFOR(j,500007 - x,0)
            if (dp[j])
                dp[j + x] = 1;
    }
    vector<int> a;
    a.PB(0);
    FOR(i,1,500007)
        if (dp[i]){
            if(i - a.back() > d)
                break;
            a.PB(i);
        }
    int res = 0;
    int id = 0;
    while(id != a.size() - 1){
        ++res;
        if (a.back() - a[id] <= d){
            id = a.size() - 1;
        }
        else{
            FOR(i,id+1,a.size()){
                if (a[i] - a[id] > d){
                    id = i - 1;
                    break;
                }
            }
        }
    }
    cout << a.back() << ' ' << res << endl;
}