#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int MAXN = 100050;
const int INF = (int)1e9 + 50;


int n,m,a,b;
int cnt[MAXN];
int in[MAXN], ex[MAXN];
int dpl[MAXN], dpr[MAXN];
int pl[MAXN], pr[MAXN];
vector<P> dl, dr;

int main(){
    for(int i = 0; i < MAXN; i++){
        cnt[i] = in[i] = ex[i] = 0;
        dpl[i] = dpr[i] = INF;
    }
    dpl[0] = dpr[0] = -1;
    scanf("%d%d", &n, &m);
    pl[0] = pr[m+1] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        in[a] ++; ex[b+1] ++;
    }
    int now = 0;
    for(int i = 1; i <= m; i++){
        now += in[i];
        now -= ex[i];
        cnt[i] = now;
    }
    for(int i = 1; i <= m; i++){
        auto pos = upper_bound(dpl, dpl+m, cnt[i]) - dpl;
        dpl[pos] = cnt[i];
        pl[i] = max(pl[i-1], (int)pos);
    }
    for(int i = m; i >= 1; i--){
        auto pos = upper_bound(dpr, dpr+m, cnt[i]) - dpr;
        dpr[pos] = cnt[i];
        pr[i] = max(pr[i+1], (int)pos);
    }
    int res = 0;
    for(int i = 1; i < m; i++){
        res = max(res, pl[i] + pr[i+1]);
    }
    cout << res;

}