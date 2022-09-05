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

int a[100007];
int b[100007];
set<int> A;
set<int> B;
vector<int> ae;
vector<int> be;

int main()
{
    int n,m;
    cin >> n >> m;
    FOR(i,0,n){
        int x;
        cin >> x;
        a[x]++;
        A.insert(x);
    }
    FOR(i,0,n){
        int x;
        cin >> x;
        b[x]++;
        B.insert(x);
    }
    vector<int> res;

    RFOR(sum,m,0){

        ae.clear();
        be.clear();
        if (A.size() < B.size()){
            for(set<int>::reverse_iterator it = A.rbegin(); it != A.rend(); ++it){
                int x = *it;
                if(x + *(B.rbegin()) < sum)
                    break;
                int y = (sum - x + m) % m;
                if (!b[y]) continue;
                int c = min(a[x] , b[y]);
                FOR(i,0,c)
                    res.PB(sum);
                a[x] -= c;
                b[y] -= c;
                if (a[x] == 0)
                    ae.PB(x);
                if (b[y] == 0)
                    be.PB(y);
            }
        }
        else{
            for(set<int>::reverse_iterator it = B.rbegin(); it != B.rend(); ++it){
                int y = *it;
                if(y + *(A.rbegin()) < sum)
                    break;
                int x = (sum - y + m) % m;
                if (!a[x])continue;
                int c = min(a[x] , b[y]);
                FOR(i,0,c)
                    res.PB(sum);
                a[x] -= c;
                b[y] -= c;
                if (a[x] == 0)
                    ae.PB(x);
                if (b[y] == 0)
                    be.PB(y);
            }
        }
        FOR(i,0,ae.size())
            A.erase(ae[i]);
        FOR(i,0,be.size())
            B.erase(be[i]);
    }

    FOR(i,0,res.size())
        cout << res[i] << ' ';

    return 0;
};