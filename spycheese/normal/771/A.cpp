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

#define name "counting"
typedef unsigned long long ull;
typedef long long ll;
#define times clock() * 1.0 / CLOCKS_PER_SEC


struct __isoff{
    __isoff(){
        if(_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
       // else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
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
const ll dd = 2e5 + 7;


vector<int> P[dd];
bool us[dd];
vector<int> Z;
void dfs(int v) {
    if(us[v]) {
        return;
    }
    us[v] = 1;
    Z.push_back(v);
    for(auto u : P[v]) {
        dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        P[a].push_back(b);
        P[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(!us[i]) {
            Z.clear();
            dfs(i);
            int mm = 0;
            for(int i = 0; i < Z.size(); i++) {
                mm += P[Z[i]].size();
            }
            ll e = Z.size();
            if(e * (e - 1) != mm) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}