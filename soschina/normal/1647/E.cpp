#include <cstdio>
#include <set>
using namespace std;
const int N = 1e5 + 1, L = 31;

int n, time, p[N][L], a[N], ind[N], target[N], ans[N], to[N];
set<int> q;
bool vis[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i][0]);
        ind[p[i][0]]++;
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cnt = 0, num;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            cnt++, num = a[i];
        }
        if(a[i] > n) a[i] = 0;
        else vis[a[i]] = true;
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]) q.insert(i);
    if(num <= n){
        for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        return 0;
    }
    time = (num - n) / cnt;
    for(int j = 1; j < L; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    for(int i = 1; i <= n; i++){
        int tmp = time;
        target[i] = i;
        for(int j = 0; tmp; j++, tmp >>= 1)
            if(tmp & 1) target[i] = p[target[i]][j];
        if(a[target[i]]){
            ans[i] = a[target[i]];
            to[target[i]] = ans[i];
            a[target[i]] = 0;
        }else{
            auto it = q.lower_bound(to[target[i]]);
            ans[i] = *it;
            q.erase(it);
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}