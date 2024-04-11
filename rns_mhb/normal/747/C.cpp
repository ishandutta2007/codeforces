#include<bits/stdc++.h>
using namespace std;

#define N 200200
int t[N], d[N], k[N], p[N];
vector <int> v;
int n, q, cnt;

int main(){
  //  freopen("a.in", "r", stdin);
    scanf("%d %d", &n, &q);
    for(int step = 1; step <= q; step ++){
        scanf("%d %d %d", t + step, k + step, d + step);
        v.clear(); cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(p[i] < t[step]){ v.push_back(i); cnt ++; }
            if(cnt >= k[step]) break;
        }
        if(cnt < k[step]){ puts("-1"); continue; }
        long long ans = 0;
        for(int i = 0; i < cnt; i ++){
            p[v[i]] = t[step] + d[step] - 1;
            ans += v[i];
        }
        printf("%I64d\n", ans);
    }
}