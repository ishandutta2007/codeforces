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

bool q[4];
int d[4] = {1,6,8,9};

int main()
{

    
    vector<int> a;
    a.PB(1);
    a.PB(6);
    a.PB(8);
    a.PB(9);

    string s;
    cin >> s;
    
    string res = "";

    int z = 0;

    FOR(i,0,s.size()){
        bool ok = 1;
        FOR(j,0,4)
            if (s[i] - '0' == d[j] && !q[j]){
                ok = 0;
                q[j] = 1;
            }
        if (s[i] == '0'){
            ok = 0;
            ++z;
        }
        if (ok)
            res += s[i];
    }

    int r = 0; 
    FOR(i,0,res.size())
        r = (10 * r + res[i] - '0') % 7;

    r = (r * 10000) % 7;

    do{
        int t = 0;
        FOR(i,0,4)
            t = (t * 10 + a[i]) % 7;
        if ((r + t) % 7 == 0){
            //cout << r << ' ' << t << endl;
            FOR(i,0,4)
                res += char(a[i] + '0');
            break;
        }
    }while(next_permutation(ALL(a)));

    FOR(i,0,z)
        res += '0';

    cout << res << endl;

}