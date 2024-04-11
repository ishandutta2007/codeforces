#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <time.h>

using namespace std;
 
#define next fdfdsfdsfdsfdsfds
#define y1 ggvfdg
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define FILL(a,b) memset((a),b,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
#define y1 asdf
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int MOD = 1000000007;
const int MAX = 1300000;

int a[305][305];
bool b[305];
bool used[305];
vector<int> A;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n,k,m;
    cin >> n >> m >> k;
    if (k == n){
        cout << -1 << endl;
        return 0;
    }


    FOR(i,0,k){
        int x;
        cin >> x;
        --x;
        A.PB(x);
        b[x] = 1;
    }
    
    int V , v1 , v2;
    FOR(i,0,n)
        if (!b[i]){
            V = i;
            used[i] = 1;
            break;
        }

    vector<pair<int,int> > res;
    if (k > 0)
        v1 = A[0];
    else{
        FOR(i,0,n)
            if (!used[i]){
                v1 = i;
                break;
            }
    }
    used[v1] = 1;

    
    if (k > 1)
        v2 = A[1];
    else{
        FOR(i,0,n)
            if (!used[i]){
                v2 = i;
                break;
            }
    }
    used[v2] = 1;
    
    res.PB(MP(V,v1));
    res.PB(MP(V,v2));
    FOR(i,0,n)
        if (!used[i]){
            res.PB(MP(v1,i));
        }

    FOR(i,0,n)
        if (!used[i] && !b[i]){
            res.PB(MP(v2,i));
        }

    FOR(i,0,n)
        if (!used[i])
            res.PB(MP(V,i));

    FOR(i,0,n){
        if (!used[i])
            FOR(j,i + 1, n)
            if (!used[j]){
                res.PB(MP(i,j));
            }
    }

    if (res.size() >= m)
    FOR(i,0,m)
        cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}