#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5 + 500;
const int INF = (int)1e9 + 500;

int n,c;
int num[MAXN];
//int dat[4 * MAXN];
multiset<ll> S;
ll dp[MAXN];
priority_queue<ll> pque;

//void init_dat(int l, int r, int x){
//    if(l == r){
//        dat[x] = num[l];
//        return ;
//    }
//    int mid = (l + r) / 2;
//    init_dat(l, mid, x*2+1);
//    init_dat(mid+1, r, x*2+2);
//    dat[x] = min(dat[x*2+1], dat[x*2+2]);
//}
//
//void update(int a, int b, int x, int l, int r, int k){
//    if(r < a || b < l) return ;
//
//    int mid = (l + r) / 2;
//    if(l == r) {
//        dat[x] = k;
//        return ;
//    }
//    update(a, b, x*2+1, l, mid, k);
//    update(a, b, x*2+2, mid+1, r, k);
//
//    dat[x] = min(dat[x*2+1], dat[x*2+2]);
//}
//
//int query(int a, int b, int x, int l, int r){
//    if(r < a || b < l) return INF;
//
//    int mid = (l + r) / 2;
//    if(a <= l && r <= b) return dat[x];
//
//    int LHS = query(a, b, x*2+1, l, mid);
//    int RHS = query(a, b, x*2+2, mid+1, r);
//
//    return min(LHS, RHS);
//}


int main(){
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    ll res = 0;
    for(int i = 0; i < c; i++) S.insert(num[i]);
    for(int i = c-1; i < n; i++){
        if(i >= c){
            S.erase(S.find(num[i-c]));
            S.insert(num[i]);
        }
        if(i >= c) pque.push(dp[i-c]);
        dp[i] = *(S.begin()) + (pque.empty() ? 0 : pque.top());
        res = max(res, dp[i]);
    }
    res = -res;
    for(int i = 0; i < n; i++) res += num[i];
    cout << res;

}