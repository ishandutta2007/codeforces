#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int n, k;
vector<pair<int,int>> al[123456];

pii dp(int at, int fr) {

    vector<pii> ch;
    for (auto x : al[at]) if (x.first != fr) {
        pii res = dp(x.first, at);
        res.first += x.second;
        res.second += x.second;
        ch.pb(res);
    }
    if (ch.empty()) return {0,0};
    
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
   
    int sm = 0, cur = 0, bst = 0;
    fo(i,0,min(k-1, (int)ch.size())) {
        sm += ch[i].first;
        if (ch[i].second - ch[i].first > cur) bst = i, cur = ch[i].second - ch[i].first;
    }
    pii res;
    res.first = sm;
    if (k-1 < ch.size()) {
        sm += ch[k-1].first;
        fo(i,k-1, (int)ch.size()) if (ch[i].second - ch[k-1].first > cur) bst = i, cur = ch[i].second - ch[k-1].first;
    }
    res.second = sm + cur;
    res.second = max(res.first, res.second);
    return res;
}
int main() {
    scanf("%d %d", &n, &k);
    fo(i,0,n-1) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        al[u].pb({v,d});
        al[v].pb({u,d});
    }
    printf("%d\n", dp(0,-1).second);

    return 0;
}