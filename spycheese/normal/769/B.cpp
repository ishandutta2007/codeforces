#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h> 
#include <list>
#include <cstring>
#include <queue>
using namespace std;

#define name "buckets"
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
//#define forn(i, n) for(int i = 0; i < (int)n; i++)
//#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC


struct __isoff{
    __isoff(){
        if(_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        //ios_bsume::sync_with_stdio(0);
        //srand(time(0));
        srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
    }
    ~__isoff(){
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int infi = 1e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 5e3 + 7;

vector<int> G[dd];
int us[dd], d = 0;

void dfs(int v){
    if(us[v]){
        return;
    }
    d++;
    us[v] = 1;
    for(auto u : G[v]){
        dfs(u);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > P;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        P.emplace_back(x, i);
    }
    vector<pair<int, int> > F;
    sort(P.begin() + 1, P.end());
    P.push_back(P.front());
    int t = n - 1;
    for(int i = n; i >= 1 && t >= 1; i--){
        while(t >= 1 && P[i].first > 0){
            P[i].first--;
            G[P[i].second].push_back(P[t].second);
            G[P[t].second].push_back(P[i].second);
            F.emplace_back(P[i].second, P[t].second);
            t--;
        }
    }
    dfs(0);
    if(d != n){
        cout << -1;
    }
    else{
        cout << F.size() << '\n';
        for(int i = 0; i < F.size(); i++){
            cout << F[i].first + 1 << ' ' << F[i].second + 1 << '\n';
        }
    }
}