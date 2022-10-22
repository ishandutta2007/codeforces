#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, d;
int ans;
int day[202020];

map<int, int> M;

int main(){
    int a;
    scanf("%d %*d %d", &N, &d);
    for (int i=1; i<=N; i++){
        scanf("%d", &a);
        M[a] = i;
    }

    while (!M.empty()){
        int m = 1;
        ans++;
        while (1){
            auto it = M.lower_bound(m);
            if (it == M.end()) break;
            m = it->first + d + 1;
            day[it->second] = ans;
            M.erase(it);
        }
    }
    printf("%d\n", ans);
    for (int i=1; i<=N; i++) printf("%d ", day[i]);
    return 0;
}