#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)2e5 + 500;

int n;
int num[MAXN];
int last[2000500];
bool vis[2000500];

int main(){
    fill(vis, vis+2000500, false);
    fill(last, last+2000500, -1);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]), last[num[i]+1] = num[i];
    int now = -1;
    for(int i = 0; i < 2000500; i++){
        if(last[i] == -1) last[i] = now;
        else now = last[i];
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(!vis[num[i]]){
            vis[num[i]] = 1;
            for(int j = 2 * num[i]; j < 2000500; j += num[i]){
                if(last[j] > num[i]) res = max(res, last[j] % num[i]);
            }
        }
    }
    cout << res;

}