#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> x(n), y(n);
        for(auto &i : x)cin >> i;
        for(auto &i : y)cin >> i;
        sort(x.begin(), x.end());
        vector<int> dist(n);
        int l = n-1, r = n-1;
        dist[l] = 1;
        while(l > 0){
            l--;
            while(x[r]-x[l] > k){
                r--;
            }
            dist[l] = r-l+1;
        }
        map<int,int> M;
        for(int i = 0; i < n; ++i){
            M[dist[i]]++;
        }
        l = 0, r = 0;
        int ans = M.rbegin()->first;
        while(r < n-1){
            M[dist[r]]--;
            if(!M[dist[r]])M.erase(dist[r]);
            while(x[r]-x[l] > k){
                l++;
            }
            ans = max(ans, r-l+1+M.rbegin()->first);
            r++;
        }
        cout << ans << "\n";
    }
}