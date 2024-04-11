#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <time.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;

vector<int> g[22];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];

    FOR(i,0,n){
        FOR(j,0,22)
            if (a[i] & (1 << j))
                g[j].PB(i);
    }

    set<int> res;

    vector<pair<int,int> > b;
    FOR(pos,0,n){
        b.clear();
        int t = a[pos];
        FOR(i,0,22)
            if (g[i].size()){
            int L = 0;
            int R = g[i].size() - 1;
            while (R - L > 1){
                int X = (L + R) / 2;
                if (g[i][X] >= pos)
                    R = X;
                else L = X;
            }
            if (g[i][L] >= pos)
                R = L;
            if (g[i][R] >= pos)
                b.PB(MP(g[i][R] , i));
        }
        sort(ALL(b));
        res.insert(t);
        FOR(i,0,b.size()){
            if (i && b[i].first != b[i - 1].first)
                res.insert(t);
            if (!(t & (1 << b[i].second)))
                t ^= 1 << b[i].second;
        }
        res.insert(t);
    }

    cout << res.size() << endl;

    return 0;
}