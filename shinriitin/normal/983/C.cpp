#include <bits/stdc++.h>

const int max_N = 2000 + 21;

const int max_S = 10000 + 21;

int n, a[max_N], b[max_N], f[2][max_S];

bool check_in(int l, int r, int x){
    if(l > r) std::swap(l, r);
    return l<=x && x<=r;
}

int cost(int l, int r, int m){
    if(l > r) std::swap(l, r);
    if(l<=m && m<=r) return r-l;
    return m<l? l+r-2*m: 2*m-l-r;
}

int main(){
    scanf("%d", &n);
    a[0] = 1;
    for(int i=1;i<=n;++i){
        scanf("%d%d", a+i, b+i);
    } 
    int cur = 0;
    memset(f[0], 0x3f, sizeof(f[0]));
    f[0][0] = 0;
    for(int i=1;i<=n;++i){
        cur ^= 1;
        memset(f[cur], 0x3f, sizeof(f[cur]));
        for(int s=0;s<10000;++s)
            if(f[cur^1][s]<0x3f3f3f3f){
                int t = s, _a[4];
                for(int j=0;j<4;++j){
                    _a[j] = t % 10;
                    t /= 10;
                }
                for(int j=1;j<=9;++j){
                    int _b[4] = {_a[0], _a[1], _a[2], _a[3]};
                    for(int k=0;k<4;++k)
                        if(check_in(a[i-1], j, _b[k]) || check_in(a[i], j, _b[k])){
                            _b[k] = 0;
                        }
                    bool flag = false;
                    for(int k=0;k<4;++k)
                        if(!_b[k]){
                            _b[k] = b[i];
                            flag = true;
break;
                        }
                    if(!flag) continue;
                    std::sort(_b, _b+4);
                    t = 0;
                    for(int k=3;~k;--k) t = t*10 + _b[k];
                    int tmp = f[cur^1][s] + cost(a[i-1], a[i], j);
                    f[cur][t] = std::min(f[cur][t], tmp);
                }
            }
    }
    int ans = 0x3f3f3f3f;
    for(int s=0;s<10000;++s){
        if(f[cur][s] == 0x3f3f3f3f) continue;
        int t = s, _a[4], mina = b[n], maxa = b[n];
        for(int j=0;j<4;++j){
            _a[j] = t % 10;
            t /= 10;
            if(_a[j] == 0) continue;
            mina = std::min(mina, _a[j]);
            maxa = std::max(maxa, _a[j]);
        }
        int tmp = f[cur][s] + std::min(cost(a[n], mina, maxa), cost(a[n], maxa, mina));
        ans = std::min(ans, tmp);
    }
    printf("%d\n", ans+2*n); 
    return 0;
}