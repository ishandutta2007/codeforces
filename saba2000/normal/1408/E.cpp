#include<bits/stdc++.h>
using namespace std;
int p[200009],s[200009],a[200009],b[200009];
int P(int x){
    if(p[x] == x) return x;
    p[x] = P(p[x]);
    return p[x];

}
void un(int x, int y){
    x = P(x); y = P(y);
    if(x==y) return;
    if(s[x] > s[y]) swap(x, y);
    s[y] += s[x];
    p[x] = y;
}
main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];

    }
    for(int i =1 ;i  <= n+m; i++){
        p[i] = i;
        s[i] = 1;
    }
    for(int i = 1; i <= m; i ++){
        cin >> b[i];
    }
    vector<pair<int,pair<int,int> > > v;
    for(int i = 1; i <= n; i++){
        int s;
        cin >> s;
        while(s--){
            int j;
            cin >> j;
            v.push_back({a[i] + b[j], {i, j}});
        }
    }
    sort(v.rbegin(), v.rend());
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        int c = v[i].first, x = v[i].second.first, y = v[i].second.second + n;
        if(P(x) == P(y)) {ans += (long long)c; continue;}
        un(x, y);
    }
    cout<<ans<<endl;



}