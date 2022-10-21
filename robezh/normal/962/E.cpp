#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500, INF = (int)1e9 + 50;
typedef long long ll;

int n;
ll x[N];
int tp[N];
int asum[N], bsum[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> x[i] >> c;
        if(c == 'R') tp[i] = 1;
        else if(c == 'B') tp[i] = 2;
        else tp[i] = 3;
    }
    for(int i = 1; i <= n; i++){
        asum[i] = asum[i-1] + (tp[i] == 1);
        bsum[i] = bsum[i-1] + (tp[i] == 2);
    }
    ll res = 0;
    int pv = -1;
    for(int i = 1; i <= n; i++){
        if(tp[i] != 3) continue;
        if(pv == -1){
            ll la = x[i], lb = x[i];
            for(int j = 1; j < i; j++){
                if(tp[j] == 1) la = min(la, x[j]);
                if(tp[j] == 2) lb = min(lb, x[j]);
            }
            res += (x[i] - la) + (x[i] - lb);
        }
        else{
            bool ain = asum[i] - asum[pv] > 0, bin = bsum[i] - bsum[pv] > 0;
            int pva = pv, pvb = pv;
            ll mna = 0, mnb = 0;
            for(int j = pv + 1; j <= i; j++){
                if(tp[j] == 1 || j == i){
                    mna = max(mna, x[j] - x[pva]);
                    pva = j;
                }
                if(tp[j] == 2 || j == i){
                    mnb = max(mnb, x[j] - x[pvb]);
                    pvb = j;
                }
            }
            res += min(3 * (x[i] - x[pv]) - (mna + mnb), 2 * (x[i] - x[pv]));
        }
        pv = i;
    }

    if(pv != -1){
        ll ra = x[pv], rb = x[pv];
        for(int i = pv + 1; i <= n; i++){
            if(tp[i] == 1) ra = max(ra, x[i]);
            if(tp[i] == 2) rb = max(rb, x[i]);
        }
        res += (ra - x[pv]) + (rb - x[pv]);
    }
    else{
        ll la = INF, lb = INF, ra = -INF, rb = -INF;
        for(int i = 1; i <= n; i++){
            if(tp[i] == 1) ra = max(ra, x[i]), la = min(la, x[i]);
            if(tp[i] == 2) rb = max(rb, x[i]), lb = min(lb, x[i]);
        }
        if(la != INF) res += ra - la;
        if(lb != INF) res += rb - lb;
    }

    cout << res << endl;
}