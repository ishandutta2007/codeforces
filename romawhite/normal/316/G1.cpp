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

vector<pair<string , pair<int,int> > > a;

int MOD = 1000000007;
int p = 1000003;

LL H(string s){
    LL h = 0;
    FOR(i,0,s.size())
        h = (h * p + s[i]) % MOD;
    return h;
}

map<int,int> b[15];

int main()
{
    
    string s;
    cin>> s;
    int n;
    cin >> n;
    FOR(i,0,n){
        string ss ;
        int l , r;
        cin >> ss >> l >> r;
        a.PB(MP(ss , MP(l , r)));
        FOR(l,0,ss.size())
            FOR(r,l , ss.size()){
                string sss = "";
                FOR(t,l , r + 1)
                    sss += ss[t];
                b[i][H(sss)]++;
        }
                
    }
    set<string> S;
    FOR(l,0,s.size())
            FOR(r,l , s.size()){
                string sss = "";
                FOR(t,l , r + 1)
                    sss += s[t];
                S.insert(sss);
        }

    int res = 0;
    for(set<string>::iterator it = S.begin(); it != S.end(); ++it){
        int h = H(*it);
        bool q = 1;
        FOR(i,0,n)
            if (b[i][h] < a[i].second.first || b[i][h] > a[i].second.second)
                q = 0;
        res += q;
    }
    cout << res << endl;
    return 0;
};