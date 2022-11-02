#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <cassert>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link
 
typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int magic = 20;

struct tr{
    int l, r, add;
    int val[magic][2];
};

int maxv;
int a[100100];
tr rmq[280280];

inline void push(int v){
    if(rmq[v].add == 0){
        return;
    }
    for(int i = 0; i < magic; i++){
        if((rmq[v].add & (1 << i)) != 0){
            swap(rmq[v].val[i][0], rmq[v].val[i][1]);
        }
    }
    if(v < maxv){
        rmq[v * 2].add ^= rmq[v].add;
        rmq[v * 2 + 1].add ^= rmq[v].add;
    }
    rmq[v].add = 0;
}

inline void calc(int v){
    for(int i = 0; i < magic; i++){
        for(int j = 0; j < 2; j++){
            rmq[v].val[i][j] = rmq[v * 2].val[i][j] + rmq[v * 2 + 1].val[i][j];
        }
    }
}

void update(int v, int l, int r, int add){
    push(v);
    if(rmq[v].l > r || rmq[v].r < l){
        return;
    }
    if(rmq[v].l >= l && rmq[v].r <= r){
        rmq[v].add ^= add;
        push(v);
        return;
    }
    update(v * 2, l, r, add);
    update(v * 2 + 1, l, r, add);
    calc(v);
}

ll get(int v, int l, int r){
    push(v);
    if(rmq[v].l > r || rmq[v].r < l){
        return 0;
    }
    if(rmq[v].l >= l && rmq[v].r <= r){
        ll res = 0;
        for(int i = 0; i < magic; i++){
            res += (1LL << i) * rmq[v].val[i][1];
        }
        return res;
    }
    return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("dragons.in", "r", stdin);
	//freopen("dragons.out", "w", stdout);
	int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    maxv = 1;
    while(maxv < n){
        maxv *= 2;
    }
    for(int i = 0; i < maxv; i++){
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < magic; j++){
            if((a[i] & (1 << j)) != 0){
                rmq[i + maxv].val[j][1]++;
            }
            else{
                rmq[i + maxv].val[j][0]++;
            }
        }
    }
    for(int i = maxv - 1; i > 0; i--){
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
        calc(i);
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        l--;
        r--;
        if(t == 1){
            printf("%I64d\n", get(1, l, r));
            continue;
        }
        int x;
        scanf("%d", &x);
        update(1, l, r, x);
    }
	return 0;
}