#include<bits/stdc++.h>
using namespace std;
int a[2009],b[2009],c[2009],d[2009];
main(){
    int t;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> c[i] >> d[i];
    }
    vector<pair<int,int> > v,u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(c[j] >= a[i] && d[j] >= b[i])
                v.push_back({c[j]-a[i], d[j]-b[i]});
        }
    }
    sort(v.begin(), v.end());
    if(v.size() == 0){
        cout<<0<<endl;
        return 0;
    }

    int ans = 1e9;
    int M = -1;
    for(int i = v.size()-1 ; i >= 0; i--){
        if(v[i].second <= M) continue;
        M = v[i].second;
        u.push_back({v[i].first, v[i].second});

    }
    ans = min(ans, u[0].first+1);
    ans = min(ans, u.back().second+1);
    for(int i = 0; i+1 < u.size(); i++){
        ans = min(ans, u[i].second + u[i+1].first+2);
    }
    cout<<ans<<endl;

}