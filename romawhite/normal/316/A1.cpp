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

const int MOD = 1000002013;

int main()
{
    string s;
    cin >> s;
    LL res = 1;
    int pw = 0;
    set<char> ss;
    if(s[0] == '?'){
        res *= 9;
    }
    int rr = 10;
    if (s[0] >= 'A' && s[0] < 'Z'){
        rr = 9;
        res *= 9;
        ss.insert(s[0]);
    }

    FOR(i,1,s.size()){
        if (s[i] == '?')
            pw++;
        if (s[i] >= 'A' && s[i] < 'Z'){
            if (ss.find(s[i]) == ss.end()){
                res *= rr;
                rr--;
                ss.insert(s[i]);
            }
        }
    }

    cout << res;
    FOR(i,0,pw)
        cout << '0';
    cout << endl;

    return 0;
};