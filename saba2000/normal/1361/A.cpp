#include<bits/stdc++.h>
using namespace std;
vector<int> v[500009];
int t[500009],f[500009];
main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<pair<int,int> > w;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        w.push_back({t[i], i});
    }
    for(int i=1; i <= n; i++){
        for(int j: v[i]){
            f[t[j]] = i;

        }
        if(f[t[i]] == i) {
            cout<<-1<<endl;
            return 0;
        }
        int k = 1;
        while(f[k] == i) k++;
        if(k != t[i]){
            cout << -1<<endl;
            return 0;
        }
    }
    sort(w.begin(),w.end());
    for(auto x : w)
        cout<<x.second<<" ";
    cout<<endl;


}