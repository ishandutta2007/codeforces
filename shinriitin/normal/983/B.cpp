#include <bits/stdc++.h>

const int max_N = 5000 + 21;

const int max_M = (int)1e5 + 21;

int n, a[max_N], f[max_N][max_N], s[max_N];

int Q, Ql[max_M], Qr[max_M], q[max_M], ans[max_M];

void update(int x){
    for(int i=x;i;--i){
        s[i] = std::max(s[i], f[i][x]);
        s[i] = std::max(s[i], s[i+1]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", a+i);
        f[i][i] = a[i];
    }
    for(int len=2;len<=n;++len)
        for(int i=1;i+len-1<=n;++i){
            f[i][i+len-1] = f[i+1][i+len-1] ^ f[i][i+len-2];
        }
    scanf("%d", &Q);
    for(int i=1;i<=Q;++i){
        scanf("%d%d", Ql+i, Qr+i);
        q[i] = i;
    }
    std::sort(q+1, q+1+Q, [&](int x, int y){return Qr[x]<Qr[y];});
    for(int i=1, r=1;i<=Q;++i){
        int x = q[i];
        while(r<=Qr[x]) update(r ++); 
        ans[x] = s[Ql[x]];
    }
    for(int i=1;i<=Q;++i)printf("%d\n", ans[i]);
    return 0;
}