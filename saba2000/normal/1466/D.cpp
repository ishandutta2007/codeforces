#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[100009],deg[100009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        for(int i = 1; i < n; i++){
            int a,b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
        }
        long long sum = 0;
        vector<int> v;
        for(int i =1; i <= n; i++){
            sum += w[i];
            for(int j =0; j < deg[i] - 1; j++)
                v.push_back(w[i]);
        }

        sort(v.rbegin(),v.rend());
        cout<<sum<<" ";
        for(int i=0 ; i<v.size(); i++){
            sum+=v[i];
            cout<<sum<<" ";
        }
        cout<<endl;
        for(int i = 1; i<= n; i++){
            deg[i] = 0;
            w[i] = 0;
        }

    }

}