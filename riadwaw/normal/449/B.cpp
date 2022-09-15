//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include<bitset>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock(); 
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0); 
    cout.precision(5);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}
typedef pair<li, li> PI;
vector<PI> g[101010];
li y[101010];
void solve(){
    int n, m, k;
    
    int cnt = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        li a, b, x;
        cin >> a >> b>> x;
        --a, --b;
        g[a].push_back(PI(b, x));
        g[b].push_back(PI(a, x));
    }
    for(int i = 0; i < k; ++i) {
        li a , x;
        cin >> a >> x;
        --a;
        if(y[a] == 0)
            y[a] = x;
        else {
            ++cnt;
            y[a] = min(y[a], x);
        }
    }
    
    
    vector<li> d(n, (li)1e18);
    d[0] = 0;
    set<PI> q;
    q.insert(PI(d[0], 0));
    
    for(int i = 1; i < n; ++i) {
        if(y[i]) {
            d[i] = y[i];
            q.insert(PI(d[i], i));
        }
        
    }
    
    
    vector<int> maydelete(n);
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(PI to: g[v]) {
            if(d[to.first] > d[v] + to.second) {
                q.erase(PI(d[to.first], to.first));
                d[to.first] = d[v] + to.second;
                q.insert(PI(d[to.first], to.first));
            }
            if(d[to.first] == d[v] + to.second) {
                maydelete[to.first] = true;
            }
        }
    }
    
    
    for(int i = 1; i < n; ++i) {
        if(maydelete[i] && y[i] != 0)
            ++cnt;
    }
    
    cout << cnt;
}