#include <cstdio>
#include <vector>
using namespace std;
const int M = 5e6 + 1, L = 30;

int n, x, trie[M][2], id;
vector<int> st[M];

long long dfs(int i, int l){
    if(!i && l != L) return 0;
    l--;
    long long ans = dfs(trie[i][0], l) + dfs(trie[i][1], l);
    if(!trie[i][0] || !trie[i][1]) return ans;
    int res = 0x7fffffff;
    for(int u : st[trie[i][0]]){
        int p = trie[i][1];
        for(int j = l - 1; j >= 0; j--){
            bool bit = u & (1 << j);
            p = trie[p][bit] ? trie[p][bit] : trie[p][!bit];
        }
        res = min(res, u ^ *st[p].begin());
    }
    return ans + res;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        int p = 0;
        for(int j = L - 1; j >= 0; j--){
            bool bit = x & (1 << j);
            p = trie[p][bit] ? trie[p][bit] : trie[p][bit] = ++id;
            st[p].push_back(x);
        }
    }
    printf("%lld\n", dfs(0, L));
    return 0;
}