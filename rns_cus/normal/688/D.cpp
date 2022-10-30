#include <bits/stdc++.h>

using namespace std;

#define N 1000100

int n, k, c[N], prime[10000], cnt[10000], vis[10000];

int main()
{
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &k);
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i ++) scanf("%d", c+i);
    int t = 0;
    for(int i = 2; i <= sqrt(k); i ++) if(k%i == 0){
        prime[t] = i;
        while(k%i == 0) k /= i, cnt[t]++;
        t ++;
    }
    if(k > 1) prime[t] = k, cnt[t] = 1, t ++;
    if(!t){puts("yes"); return 0;}
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < t; j ++){
            int cn = 0;
            while(c[i]%prime[j] == 0) c[i] /= prime[j], cn++;
            if(cn >= cnt[j]) vis[j] = 1;
        }
    }
    if(*min_element(vis,vis+t) == 1) puts("yes");
    else puts("no");
    return 0;
}