#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 100;

int n,m,q;
unordered_map<int, int> mp[N], ans[N];

int find(int c, int i){
    return mp[i][c] > 0 ? mp[i][c] = find(c, mp[i][c]) : i;
}
void unite(int c, int i, int j){
    if((i = find(c, i)) == (j = find(c, j))) return ;
//    if(mp[i][c] > mp[j][c]){
//        int tmp = i; i = j, j = tmp;
//    }
//    mp[i][c] += mp[j][c] - 1;

    mp[j][c] = i;
}

bool same(int c, int i, int j){
    return find(c, i) == find(c, j);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        unite(c, a, b);
    }
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(mp[a].size() > mp[b].size()){
            int tmp = b; b = a, a = tmp;
        }
        if(ans[a].find(b) == ans[a].end()){
            int res = 0;
            for(auto p : mp[a]){
                if(mp[b].find(p.first) != mp[b].end() && same(p.first, a, b)) res++;
            }
            ans[a][b] = res;
        }
        printf("%d\n", ans[a][b]);
    }
}