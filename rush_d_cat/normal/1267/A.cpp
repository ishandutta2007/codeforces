
#include <bits/stdc++.h>
#define LL long long
#define pii pair<long long, int >
using namespace std;
const int N = 2e5 + 7;

struct node{
    LL l, r, x;
}p[N];

bool cmp(node x, node y){
    return x.l < y.l;
}

LL b[N * 2];

int main(){
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &p[i].l, &p[i].r, &p[i].x);
        p[i].r = p[i].r - p[i].x;
        b[++cnt] = p[i].l;
        b[++cnt] = p[i].r;
    }
    sort(b + 1, b + cnt + 1);
    sort(p + 1, p + n + 1, cmp);
    priority_queue<pii, vector<pii >, greater<pii > > Q1, Q2;

    for (int i = 1; i <= n; i++){
        Q1.push({p[i].l + p[i].x, i});
    }


    int j = 1;
    LL k = 0;
    LL ans = 0;
    while (true){
        while (!Q1.empty()){
            pii now = Q1.top();
            if (p[now.second].l < k) Q1.pop();
            else break;
        }
        while (!Q2.empty()){
            pii now = Q2.top();
            if (p[now.second].r < k) Q2.pop();
            else break;
        }
        //printf("%d %d\n", Q1.size(), Q2.size());
        if (Q1.empty() && Q2.empty()) break;
        if (Q2.empty() || (!Q1.empty() && Q1.top().first < k + Q2.top().first)){
            ans ++;
            //printf("%d ^*", k);
            k = Q1.top().first;
            //printf("%d\n", k);
        } else {
            LL t = 1;

            LL x = lower_bound(b + 1, b + cnt + 1, k) - b;
            x = b[x];
            if (!Q1.empty()){
                x = min(x, Q1.top().first);
            }
            t = max(1LL, (x - k) / Q2.top().first - 3);
            ans += t;
            //printf("%d ^*^ ", k);
            //printf("%lld %lld ", t, x);
            k = k + Q2.top().first * t;
            //printf("%d\n", k);
        }
        //printf("%lld\n", k);
        while (j <= n){
            //printf("%d %lldssda\n", j, p[j].l);
            if (p[j].l <= k) Q2.push({p[j].x, j}), j++;
            else break;
        }
    }
    printf("%lld", ans);
    return 0;
}