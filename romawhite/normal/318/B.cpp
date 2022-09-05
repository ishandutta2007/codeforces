//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    if (s.size() < 5){
        cout << 0 << endl;
        return 0;
    }
    vector<int> a;
    vector<int> b;
    FOR(i,0,s.size() - 4){
        if (s.substr(i,5) == "heavy")
            a.PB(i);
        if (s.substr(i,5) == "metal")
            b.PB(i);
    }

    LL res = 0;
    int j = 0;
    FOR(i,0,a.size()){
        while (j < b.size() && b[j] < a[i]) ++j;
        res += b.size() - j;
    }
    cout << res << endl;
    return 0;
};