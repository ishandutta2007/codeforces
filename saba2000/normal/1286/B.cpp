#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[2009],c[2009];
int ans[2009];
vector<int> v[2009],t[2009];
int NO = 0;
void dfs(int x){
    vector<int> s;
    for(int y : v[x]){
        dfs(y);
        for(int u : t[y]){
            s.push_back(u);
        }
    }
    if(c[x] > s.size()) NO = 1,s.push_back(x), t[x] = s;
    else{
        if(t[x].size() == c[x]) t[x].push_back(x);
        for(int y : s){
            t[x].push_back(y);
            if(t[x].size() == c[x]) t[x].push_back(x);}
    }
}
main(){
    int n;
    int r;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i] >> c[i];
        if(p[i] == 0) r = i;
        else v[p[i]].push_back(i);
    }
    dfs(r);
    for(int i = 0; i < t[r].size(); i++){
        ans[t[r][i]] = i+1;}

    if(NO) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i = 1; i <= n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

}