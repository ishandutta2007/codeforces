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
    //freopen("fraction.in" , "r" , stdin);freopen("fraction.out" , "w" , stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    FOR(i,0,n){
        string s;
        int st;
        cin >> s >> st;
        if (s == "ATK")
            a.PB(st);
        else b.PB(st);
    }
    FOR(i,0,m){
        int st;
        cin >> st;
        c.PB(st);
    }
    int res = 0;
    sort(ALL(a));
    sort(ALL(c));
    sort(ALL(b));

    FOR(l,0,min(a.size() , c.size()) + 1){
        int t = 0;
        bool q = 1;
        FOR(j,0,l)
            if (a[j] > c[c.size() - l + j])
                q = 0;
            else
                t += c[c.size() - l + j] - a[j];
        if (q)
            res = max(res , t);
    }

    if (b.size() + a.size() <= c.size()){
        bool ok = 1;
        FOR(i,0,b.size()){
            bool q = 1;
            FOR(j,0,c.size())
                if (c[j] > b[i]){
                    swap(c[j] , c[c.size() - 1]);
                    c.pop_back();
                    q = 0;
                    sort(ALL(c));
                    break;
                }
            if (q){
                ok = 0;
                break;
            }
        }
        FOR(i,0,a.size())
            if (a[i] > c[c.size() - a.size() + i])
                ok = 0;
        
        if (ok){
            int t = 0;
            FOR(i,0,c.size())
                t += c[i];
            FOR(i,0,a.size())
                t -= a[i];
            res = max(res , t);
        }
    }
    cout << res << endl;
    return 0;
};