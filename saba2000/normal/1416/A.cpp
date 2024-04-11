#include<bits/stdc++.h>
using namespace std;
int a[300009];
vector<int> v[300009];
int ans[300009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        for(int i= 1; i <= n; i++){

            cin >> a[i];
            v[a[i]].push_back(i);
            ans[i] = -1;
        }
        int j = n;
        for(int i = 1; i <= n; i++){
            if(v[i].size() == 0) continue;
            int k = max(v[i][0], n - v[i].back() + 1);
            for(int j = 0; j +1 < v[i].size(); j++){
                k = max(k, v[i][j+1] - v[i][j]);
            }
            for(int u = k; u <= j; u++){
                ans[u] = i;
            }
            j = min(j, k - 1);
        }
        for(int i = 1; i <= n; i++)
            cout<<ans[i]<<" ";
        for(int i= 1; i <= n; i++){
            v[i].clear();
            ans[i] = 0;
            a[i] = 0;

        }
        cout<<endl;
    }

}