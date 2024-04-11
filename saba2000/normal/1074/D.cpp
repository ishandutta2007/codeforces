#include<bits/stdc++.h>
using namespace std;
const int mx = 6e5;
int p[mx], xr[mx], s[mx];
int cnt;
map<int,int> M;
int par(int x){
    if(p[x] == x) return x;
    return par(p[x]);
}
int Xor(int x){
    if(p[x] == x) return 0;
    return xr[x] ^ Xor(p[x]);
}
void upd(int l, int r, int X){
    r++;
    if(!M[l]) M[l] = ++cnt;
    if(!M[r]) M[r] = ++cnt;
    int x = par(M[l]), y = par(M[r]);
    if(x == y) return;
    X = Xor(M[l]) ^ Xor(M[r]) ^ X;
    if(s[x] > s[y]) swap(x, y);
    p[x] = y;
    s[y] += s[x];
    xr[x] = X;
}
int Ans(int l, int r){
    r++;
    l = M[l], r = M[r];
    if(!l || !r) return -1;
    if(par(l) != par(r)) return -1;
    return Xor(l) ^ Xor(r);
}
main(){
    int q;
    cin >> q;
    for(int i = 1; i <= 2*q; i++)
        p[i] = i, s[i] = 1, xr[i] = 0;
    int last = 0;
    while(q --){
        int t;
        scanf("%d", &t);
        //type 1
        if(t == 1){
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);

            l ^= last; r ^= last; x ^= last;
            if(l > r) swap(l, r);
            upd(l, r, x);
        }
        //type 2
        if(t == 2){
            int l, r;
            scanf("%d %d", &l, &r);
            l ^= last; r ^= last;
            if(l > r) swap(l, r);
            int ans = Ans(l, r);
            printf("%d\n", ans);
            last = ans;
            if(last == -1) last = 1;
        }
    }

}