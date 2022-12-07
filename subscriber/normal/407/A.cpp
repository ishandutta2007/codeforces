#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int a, b;
vector<pt> v, vv;

void gen(int x) {
    v.clear();
    for (int i = 1; i < x; i++) for (int j = 1; j < x; j++) if (i * i + j * j == x * x) {
        v.pb(mp(i, j));
        v.pb(mp(i, -j));
        v.pb(mp(-i, j));
        v.pb(mp(-i, -j));
    }
}

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);
    cin >> a >> b;
    gen(b);
    vv = v;
    gen(a);
    for (int i = 0; i < v.size(); i++) for (int j = 0; j < vv.size(); j++) {
        int d = (v[i].F - vv[j].F) * (v[i].F - vv[j].F) + (v[i].S - vv[j].S) * (v[i].S - vv[j].S);
        if (d == a * a + b * b) {
            if (v[i].F == vv[j].F) continue;
            if (v[i].S == vv[j].S) continue;
            puts("YES");
            cout << 0 << " " << 0 << endl;
            cout << v[i].F << " " << v[i].S << endl;
            cout << vv[j].F << " " << vv[j].S << endl;
            return 0;
        }
    }
    puts("NO");
    return 0;
}