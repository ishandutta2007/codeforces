
#include<bits/stdc++.h>
using namespace std;
int a[100009];
int p[100009];
int dp[100009];
main(){
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        v.push_back({a[i], i});
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++)
        p[v[i].second] = i;
    for(int i = n - 1; i >= 0; i--){
        if(v[i].first <= 300){
            for(int j = 0; j < n; j++){
                if(v[j].first > v[i].first &&
                   (v[j].second - v[i].second)%v[i].first == 0)
                    if(dp[j] == 0) dp[i] = 1;
            }
        }
        else{
            for(int d = v[i].second % v[i].first;
                    d < n; d+=v[i].first){
                    int j = p[d];
                       if(v[j].first > v[i].first &&
                   (v[j].second - v[i].second)%v[i].first == 0)
                    if(dp[j] == 0) dp[i] = 1;
                }
        }
    }
    string ans = "";
    for(int i = 0; i < n; i++)
        if(dp[p[i]]) ans +='A';
    else ans+='B';
    cout<<ans<<endl;
}