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

int pr[100007];
int dg[100007];
bool t[100007];
int d[100007];
int p[100007];

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    FOR(i,0,n)
        cin >> t[i];

    FOR(i,0,n){
        cin >> pr[i];
        pr[i]--;
        if (pr[i] != -1)
            dg[pr[i]]++;
    }

    FILL(d,-1);
    FOR(i,0,n)
        if (t[i]){
            d[i] = 0;
            p[i] = -1;
            int v = i;
            while (pr[v] != -1 && dg[pr[v]] == 1){
                d[pr[v]] = d[v] + 1;
                p[pr[v]] = v;
                v = pr[v];
            }
        }

    int r = -1;
    int v;
    FOR(i,0,n){
        if (d[i] > r){
            r = d[i];
            v = i;
        }
    }
    cout << r + 1 << endl;
    while (v != -1){
        cout << v + 1 << ' ';
        v = p[v];
    }
    return 0;
}