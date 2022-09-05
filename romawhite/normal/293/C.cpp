//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include <time.h>
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
#define INF                     (2000000000)
#define FILL                    CLEAR

void rrr(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
}



int main()
{
    rrr();
    LL n;
    cin >> n;
    if (n % 3){
        cout << 0 << endl;
        return 0;
    }
    n /= 3;
    vector<LL> a;
    for(LL i = 1; i*i <= n; ++i)
        if (n % i == 0){
            a.PB(i);
            if (i * i != n)
                a.PB(n / i);
        }

    sort(ALL(a));

    int nm = (a.size() + 1) / 2;
    int res = 0;
    FOR(i,0,nm){
        LL t = n / a[i];
        FOR(j,i,nm){
            if (t % a[j]) continue;
            LL d = t / a[j];
            if (d < a[j]) break;
            if ((a[i] + a[j] + d) & 1) continue;
            if (a[i] + a[j] > d){
                //cout << a[i] << ' ' << a[j] << ' ' << d << endl;
                if (a[i] == a[j]){
                    if (a[i] == d)
                        res += 1;
                    else res += 3;
                }
                else{
                    if (a[i] == d || a[j] == d)
                        res += 3;
                    else res += 6;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
};