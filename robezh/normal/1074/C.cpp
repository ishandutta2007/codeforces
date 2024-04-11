#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500;
const int INF = (int)2e9;
typedef long long ll;

int n;
int x[N], y[N];
int u, d, l, r;
int umax, dmax, lmax, rmax = -INF;
ll res[N];

int get_cost(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int get_res(int a, int b, int c){
    return get_cost(a, b) + get_cost(a, c) + get_cost(b, c);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(y[i] > y[u]) u = i;
        if(y[i] < y[d]) d = i;
        if(x[i] > x[r]) r = i;
        if(x[i] < x[l]) l = i;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, max(get_res(u, l, i), get_res(u, r, i)));
        res = max(res, max(get_res(d, l, i), get_res(d, r, i)));
    }
    int res4 = (x[r] - x[l] + y[u] - y[d]) * 2;
    printf("%d ", res);
    for(int i = 4; i <= n; i++) printf("%d ", res4);
}