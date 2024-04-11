#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;

vector<int> e[MAXN];
bool vis[MAXN];
vector<int> q1, q2;

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    int h, t;
    int i, j, k;
    scanf("%d%d%d%d", &n, &m, &h, &t);
    for(i = 0; i < m; i++){
        scanf("%d%d", &j, &k);
        e[j].pb(k);
        e[k].pb(j);
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j < e[i].size(); j++)
            if(e[i].size() > h && e[e[i][j]].size() > t){
                int cnt = 0;
                for(k = 0; k < e[i].size() && k < (h+t+2); k++)
                    vis[e[i][k]] = 1;
                for(k = 0; k < e[e[i][j]].size() && k < (h+t+2); k++)
                    cnt += vis[e[e[i][j]][k]];
                for(k = 0; k < e[i].size() && k < (h+t+2); k++)
                    vis[e[i][k]] = 0;
                if(min(h+t+2, (int)e[i].size()) + min(h+t+2, (int)e[e[i][j]].size()) - cnt >= h+t+2)
                    break;
            }
        if(j < e[i].size())
            break;
    }
    if(i == n+1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        j = e[i][j];
        printf("%d %d\n", i, j);
        for(k = 0; k < e[i].size(); k++){
            if(e[i][k] != j){
                q1.pb(e[i][k]);
            }
        }
        for(k = 0; k < e[j].size(); k++){
            if(e[j][k] != i){
                q2.pb(e[j][k]);
            }
        }
        for(i = 0; i < q2.size(); i++)
            vis[q2[i]] = 1;
        for(i = 0; i < q1.size() && h; i++)
            if(!vis[q1[i]]){
                printf("%d ", q1[i]);
                h--;
            }
        for(i = 0; i < q1.size() && h; i++)
            if(vis[q1[i]]){
                printf("%d ", q1[i]);
                vis[q1[i]] = 0;
                h--;
            }
        printf("\n");
        for(i = 0; i < q2.size() && t; i++){
            if(vis[q2[i]]){
                printf("%d ", q2[i]);
                t--;
            }
        }
        printf("\n");
                
    }
    return 0;
}