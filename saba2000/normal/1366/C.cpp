#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>> m;
        vector<int> v[100];
        for(int i =1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int a;
                cin>>a;
                if(i + j != n+m +2 -i - j)
                v[min(i+j, n+m+2-i-j)].push_back(a);
            }
        }
        int ans = 0;
        for(int i = 2; i <= n+m; i++){
            sort(v[i].begin(), v[i].end());
            int k = 1, m = 1;
            if(v[i].size() <= 1) continue;
            for(int j = 1; j < v[i].size(); j++){
                if(v[i][j] == v[i][j-1]) {k++; continue;}
                m = max(m, k);
                k = 1;
            }
            m = max(m, k);
            ans += v[i].size() - m;
        }
        cout<<ans<<endl;

    }
}