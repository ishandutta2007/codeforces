#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ll long long
using namespace std;
vector<int> v[500009];
ll c[500009];
ll A1 =1610612741, B1 = 1098534113;
ll A2 =1124810749, B2 = 1743951611;
ll H1[500009],H2[500009];
void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
    }
    for(int i = 1; i <= m; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        v[b].push_back(a);
    }

    vector<pair<pair<ll,pair<ll,ll> >,int> > w;

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(),v[i].end());
        for(int x : v[i]){
            H1[i] = (H1[i] * A1 + x) % B1;
            H2[i] = (H2[i] * A2 + x) % B2;
        }
        if(v[i].size() == 0) continue;
        w.push_back({{v[i].size(), {H1[i],H2[i]}}, i});
    }
    sort(w.begin(),w.end());
    ll S = c[w[0].second], pas = 0;
    for(int i = 1; i < w.size(); i++){
        if(w[i].first == w[i-1].first) S += c[w[i].second];
        else pas = __gcd(pas, S), S = c[w[i].second];
    }
    pas = __gcd(pas, S);
    printf("%lld\n",pas);
    for(int i = 1; i <= n; i++)
        v[i].clear(), c[i] = 0, H1[i] = 0,H2[i] = 0;
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

/*
A B
(A,B,C)


*/