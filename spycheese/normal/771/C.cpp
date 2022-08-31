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

int n, k;

vector<int> P[dd];

vector<int> dp[dd];

ll sum = 0;

void dfs1(int v, int p) {
    vector<int> Z(k);
    Z[0] = 1;
    for(auto u : P[v]) {
        if(u != p) {
            dfs1(u, v);
            for(int j = 0; j < k; j++) {
                for(int l = 0; l < k; l++) {
                    ll t = (k - (1 + l + j) % k) % k;
                    sum += t * Z[l] * dp[u][j];
                }
            }
            for(int j = 0; j < k; j++) {
                Z[(j + 1) % k] += dp[u][j];
            }
        }
    }
    dp[v] = Z;
}
/*
void dfs2(int v, int p, vector<int> Q) {
    vector<int> Z = dp[v];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            ll t = (i + j) % k;
            sum -= t * Q[i] * Z[j];
        }
    }

}*/

int main() {
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        P[a].push_back(b);
        P[b].push_back(a);
    }
    dfs1(0, -1);
    for(int i = 1; i < n; i++) {
        ll s = 0;
        for(int j = 0; j < k; j++) {
            s += dp[i][j];
        }
        sum += s * (n - s);
    }
    //dfs2(0, -1, vector<int>(k));
    cout << sum / k;
}