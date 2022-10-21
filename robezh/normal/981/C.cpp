#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,a,b;
vector<int> G[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int core = -1;
    for(int i = 1; i <= n; i++){
        if(G[i].size() >= 3){
            if(core != -1) return !printf("No");
            else core = i;
        }
    }
    if(core == -1){
        printf("Yes\n1\n");
        for(int i = 1; i <= n; i++){
            if(G[i].size() == 1) printf("%d ", i);
        }
    }
    else{
        vector<int> res;
        for(int i = 1; i <= n; i++){
            if(G[i].size() == 1) res.push_back(i);
        }
        printf("Yes\n%d\n", res.size());
        for(int x : res){
            printf("%d %d\n", core, x);
        }
    }
}