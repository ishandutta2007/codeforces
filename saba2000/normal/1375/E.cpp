#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ans;
int a[1009];
void solve(vector<int> v){
    int m = -1;
    vector<int> w;
    if(v.size() == 1) return;
    for(int i = 0; i < v.size(); i++)
        if(m == -1 || a[v[i]] >= a[v[m]]) m = i;
    for(int i = 0; i < v.size(); i++)
        if(i != m) w.push_back(v[i]);
    solve(w);

    for(int i = v.size()-1; i >m; i--)
        ans.push_back({v[m], v[i]});
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i =1 ;i <= n; i++)
        cin >> a[i];
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    solve(v);
    cout<<ans.size()<<endl;
    for(auto x : ans)
        cout<<x.first<<" "<<x.second<<endl;
}