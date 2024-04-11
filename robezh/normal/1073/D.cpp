#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n;
ll T;
ll dat[4*N];
int num[N];
ll cnt;

void init_dat(int l, int r, int x){
    if(l == r){dat[x] = num[l]; return ;}

    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1);
    init_dat(mid+1, r, x*2+2);
    dat[x] = dat[2*x+1] + dat[2*x+2];
}

void update(int a, int b, int x, int l, int r, int val){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = val;
        return ;
    }
    update(a, b, x*2+1, l, mid, val);
    update(a, b, x*2+2, mid+1, r, val);

    dat[x] = dat[2*x+1] + dat[2*x+2];
}

int query(int x, int l, int r, ll val){
    if(l == r) return l;

    int mid = (l + r) / 2;
    if(dat[2*x+1] > val) return query(2*x+1, l, mid, val);
    else return query(2*x+2, mid+1, r, val - dat[2*x+1]);
}

int main(){
    scanf("%d%I64d", &n, &T);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    init_dat(0, n-1, 0);

    cnt = n;
    ll res = 0;
    while(cnt > 0){
        ll ts = T / dat[0];
        res += ts * cnt;
        T -= ts * dat[0];
        while(cnt > 0 && T < dat[0]){
            int q = query(0, 0, n-1, T);
            update(q, q, 0, 0, n-1, 0);
            cnt--;
        }
//        cout << cnt << " " << T << endl;
    }
    cout << res << endl;

}