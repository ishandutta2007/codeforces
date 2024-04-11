#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> v(n+m,0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int a; cin>> a;
                v[i+j]^=a;
            }
        }
        bool good = 1;
        for(int i = 0; i < n+m; ++i){
            good&=(v[i] == 0);
        }
        if(!good)cout << "Ashish\n";
        else cout << "Jeel\n";
    }    
}