#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef double du;
typedef long long ll;
const int MAXN = 5004;

int f[MAXN];
int s[MAXN], next[MAXN*2], b[MAXN*2];
int size[MAXN];
int ans[MAXN];
bool vis[MAXN];
int n;

void dfs(int i){
    int j, k;
    vis[i] = 1;
    size[i] = 1;
    for(j = s[i]; j != -1; j = next[j]){
        if(!vis[b[j]]){
            dfs(b[j]);
            size[i] += size[b[j]];
            vis[b[j]] = 0;
        }
    }
    memset(f, 0, sizeof f);
    f[0] = 1;
    f[n-size[i]] = 1;
    for(j = s[i]; j != -1; j = next[j]){
        if(!vis[b[j]]){
            for(k = n; k >= size[b[j]]; k--)
                f[k] |= f[k-size[b[j]]];
            vis[b[j]] = 1;
        }
    }
    for(k = 0; k <= n; k++)
        ans[k] |= f[k];
}

int main(){
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n;
    int i, j;
    scanf("%d", &n);
    memset(s, -1, sizeof s);
    for(i = 1; i < n; i++){
        scanf("%d%d", &b[i], &b[i+n]);
        next[i] = s[b[i+n]];
        s[b[i+n]] = i;
        next[i+n] = s[b[i]];
        s[b[i]] = i+n;
    }
    ::n = n;
    dfs(1);
    j = 0;
    for(i = 1; i < n-1; i++)
        j += ans[i];
    printf("%d\n", j);
    for(i = 1; i < n-1; i++)
        if(ans[i])
            printf("%d %d\n", i, n-1-i);
    return 0;
}