#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,int>> vi(1e7+5,{1,1});
    for(int i = 2; i < 1e7+5; ++i){
        if(vi[i].first == 1){
            for(int j = i; j < 1e7+5; j+=i){
                if(vi[j].first == 1)vi[j].first = i;
                else vi[j].second*=i;
            }
        }
    }
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v)cin >> x;
    vector<pair<int,int>> ans;
    for(auto x : v)ans.push_back(vi[x]);
    for(auto x : ans)cout << (x.second == 1 ? -1 : x.first) << ' ';
    cout << '\n';
    for(auto x : ans)cout << (x.second == 1 ? -1 : x.second) << ' ';
    cout << '\n';
}