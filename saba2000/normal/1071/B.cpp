#include<bits/stdc++.h>
using namespace std;
string a[2009];
int dx[2] ={1,0};
int dy[2] ={0,1};
main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = ' '+a[i];
    }
    string ans = "";
    vector<pair<pair<int,int>,int> > v;
    if(k == 0 || a[1][1] == 'a') v.push_back({{1,1},k}), ans +=a[1][1];
    else v.push_back({{1,1},k-1}), ans += 'a';
    for(int i = 3; i <= 2*n; i++){
        vector<pair<pair<int,int>,int> > v1, v2;
        char X = 'z';
        for(int i = 0; i < v.size(); i++){
            int x = v[i].first.first, y = v[i].first.second, K = v[i].second;
            char z;
            for(int j = 0; j < 2; j++){
                int nx = x +dx[j], ny = y + dy[j];
                if(nx > n || ny > n) continue;
                if(a[nx][ny] == 'a') {
                     if(X > 'a') v1.clear();
                     X = 'a';
                     v1.push_back({{nx,ny},K});
                }
                else if(K){
                    if(X > 'a') v1.clear();
                    X = 'a';
                    v1.push_back({{nx,ny},K-1});
                }
                else{
                    if(X > a[nx][ny]) v1.clear();
                    X = min(X, a[nx][ny]);
                    if(X == a[nx][ny]) v1.push_back({{nx,ny},K});
                }
            }
        }
        ans += X;
        v.clear();
        for(int i = 0; i < v1.size(); i++){
            if(i && v1[i].first == v1[i-1].first){
                v.back().second = max(v.back().second, v1[i].second);
            }
            else v.push_back(v1[i]);
        }
    }
    cout<<ans<<endl;


}