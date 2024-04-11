#include <bits/stdc++.h>
using namespace std;
#define N 200100

int f[N] = {0}, ans[N];
vector<int> v[N], a;

int main(){
    int n, k, tot = 0;
    scanf("%d", &n);
    a.push_back(0);
    for(int i = 0; i < n; i ++){
        scanf("%d", &k);
        if(f[k] == 0) a.push_back(k);
        f[k] ++;
    }
    sort(a.begin(), a.end());
    int po = 1;
    v[1].push_back(a[1]);
    for(int i = 1; i < a.size() - 1; i ++){
        if(a[i + 1] - a[i] <= 1){
            v[po].push_back(a[i + 1]);
        }
        else {
            po = i + 1;
            v[po].push_back(a[po]);
        }
    }
    for(int i = 1; i < N; i ++){
        if(!v[i].empty()){
            int t = v[i][0];
            ans[t] = f[v[i][0]];
            for(int j = 1; j < v[i].size(); j ++){
                if(f[v[i][j]] >= 2) ans[t] += f[v[i][j]];
                else{
                    ans[t] += f[v[i][j]];
                    t = v[i][j];
                    ans[t] = 1;
                }
            }
        }
    }
    int maxn = -1; int flag;
    for(int i = 1; i < N; i ++){
        if(maxn < ans[i]){
            maxn = ans[i];
            flag = i;
        }
    }
    printf("%d\n", maxn);
    int j;
    for(j = flag; ; j ++){
        for(int i = 0; i < f[j]; i ++){
            tot ++;
            if(tot == maxn) break;
        }
        if(tot == maxn) break;
    }
    printf("%d ", flag);
    for(int i = flag; i <= j; i ++){
        for(int l = 0; l < f[i] - 1; l ++){
            printf("%d ", i);
        }
    }
    for(int i = j; i > flag; i --) printf("%d ", i);
}