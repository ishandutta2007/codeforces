#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tot, inv;
int f[300009];
    int n;
void upd(int x, int d){
    while(x <= n){
        f[x] += d;
        x += (x & -x);
    }
}
int cnt(int x){
    int pas = 0;
    while(x){
        pas += f[x];
        x -= (x & -x);
    }
    return pas;
}
void INV(vector<int> a, vector<int> b){
    tot += (ll)a.size() * (ll)b.size();
    for(int i = 0; i < a.size(); i++){
        upd(a[i],1);
    }
    for(int i = 0; i < b.size(); i++){
        inv += a.size()-cnt(b[i]);
    }
     for(int i = 0; i < a.size(); i++){
        upd(a[i],-1);
    }
}
int a[300009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 1; i <= n; i++){

        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(),v.end());

    ll ans = 0, xr = 0;
    for(int j = 30; j >= 0; j--){
        tot = 0; inv =0 ;
        vector<int> a, b;
        for(int i = 0; i < n; i++){
            if(i == 0 || (v[i].first>>(j+1)) == (v[i-1].first>>(j+1))){
                if(v[i].first & (1 << j)) b.push_back(v[i].second);
                else a.push_back(v[i].second);
            }
            else{
                INV(a,b);
                a.clear(); b.clear();
                if(v[i].first & (1 << j)) b.push_back(v[i].second);
                else a.push_back(v[i].second);
            }
        }
        INV(a,b);
        if(inv <= tot - inv) ans += inv;
        else ans += tot - inv, xr ^= (1<<j);

    }
    cout<<ans<<" "<<xr<<endl;


}