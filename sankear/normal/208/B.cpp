#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);
const int iters = 100;
const double tl = 1.9;
const ll hx = ll(2e5 + 3);
const int MOD = int(1e6 + 7);
const int SIZE = int(2e7);

int it = 0, sz = 0;
double start;
string s[100];
int first[MOD];
ll mem[SIZE + 10];
int next[SIZE + 10];

inline ll calc(string &s){
    return s[0] * hx + s[1];
}

inline bool can(string &a, string &b){
    return a[0] == b[0] || a[1] == b[1];
}

inline void add(ll hash){
    int need = hash % MOD;
    if(need < 0){
        need += MOD;
    }
    for(int i = first[need]; i > 0; i = next[i]){
        if(mem[i] == hash){
            return;
        }
    }
    if(sz + 1 < SIZE){
        mem[++sz] = hash;
        next[sz] = first[need];
        first[need] = sz;
    }
}

inline bool find(ll hash){
    int need = hash % MOD;
    if(need < 0){
        need += MOD;
    }
    for(int i = first[need]; i > 0; i = next[i]){
        if(mem[i] == hash){
            return true;
        }
    }
    return false;
}

map < vector <string>, bool> memo;

void go(int x){
    if(x == 0){
        printf("YES\n");
        exit(0);
    }
    it++;
    if(it >= iters){
        if((clock() - start) / CLOCKS_PER_SEC > tl){
            printf("NO\n");
            exit(0);
        }
        it = 0;
    }
    /*ll hash = 0;
    for(int i = 0; i <= x; i++){
        hash = hash * hx + calc(s[i]);
    }
    if(find(hash)){
        return;
    }
    add(hash);*/
    vector <string> cur;
    for(int i = 0; i <= x; i++){
        cur.pb(s[i]);
    }
    if(memo.find(cur) != memo.end()){
        return;
    }
    memo[cur] = true;
    if(can(s[x - 1], s[x])){
        swap(s[x], s[x - 1]);
        go(x - 1);
        swap(s[x], s[x - 1]);
    }
    if(x - 3 >= 0 && can(s[x - 3], s[x])){
        swap(s[x], s[x - 3]);
        go(x - 1);
        swap(s[x], s[x - 3]);
    }
}

int main(){
    start = clock();
#ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    //cout << (sizeof(mem) + sizeof(next)) / 1024 / 1024 << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    go(n - 1);
    printf("NO\n");
    return 0;
}