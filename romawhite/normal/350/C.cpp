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

bool comp(pair<int,int> a,pair<int,int> b){
    return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}


int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    vector<pair<int,int> > a;
    FOR(i,0,n){
        int x,y;
        cin >> x >> y;
        a.PB(MP(x,y));
    }
    
    sort(ALL(a),comp);

    vector<pair<int,pair<int,char> > > res;

    FOR(i,0,n){
        int x = a[i].first;
        int y = a[i].second;

        if (x != 0){
            if (x > 0)
                res.PB(MP(1,MP(x,'R')));
            else res.PB(MP(1,MP(-x,'L')));
        }
        if (y != 0){
            if (y > 0)
                res.PB(MP(1,MP(y,'U')));
            else res.PB(MP(1,MP(-y,'D')));
        }
        res.PB(MP(2,MP(0,'a')));
        if (x != 0){
            if (x > 0)
                res.PB(MP(1,MP(x,'L')));
            else res.PB(MP(1,MP(-x,'R')));
        }
        if (y != 0){
            if (y > 0)
                res.PB(MP(1,MP(y,'D')));
            else res.PB(MP(1,MP(-y,'U')));
        }
        res.PB(MP(3,MP(0,'a')));

    }

    cout << res.size() << endl;
    FOR(i,0,res.size()){
        if (res[i].first == 1){
            cout << res[i].first << ' ' << res[i].second.first << ' ' << res[i].second.second << '\n';
        }
        else
            cout << res[i].first << '\n';
    }

    return 0;
}