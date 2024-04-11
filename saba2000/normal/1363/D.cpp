#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[1009];
int f[1009];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int c;
        cin >> c;
        while(c--){
            int x;
            cin >>x;
            v[i].push_back(x);
        }
    }
    cout<<"? "<<n <<" ";
    for(int i = 1; i <= n; i++)
        cout<<i<<" ";
    cout<<endl;
    int mx;
    cin>>mx;
    int lo = 1, hi = n;
    while(lo < hi){
        int mid = (lo +hi)/2;
        cout<<"? "<<mid - lo + 1 <<" ";
        for(int i = lo; i <= mid; i++)
            cout<<i<<" ";
        cout<<endl;
        int x;
        cin >> x;
        if(x == mx) hi = mid;
        else lo = mid+1;
    }
    vector<int> ans;
    for(int i = 1; i <= k; i++){
        int ok = 0;
        for(int j : v[i])
            if(j == lo) ok = 1;
        if(!ok) {ans.push_back(mx); continue;}
        for(int i = 1; i <= n; i++)

            f[i] = 0;
        for(int j : v[i])
            f[j] = 1;
        cout<<"? "<<n - v[i].size()<<" ";
        for(int i = 1; i <= n; i++)
            if(f[i] == 0) cout<<i<<" ";
        cout<<endl;
        int x;
        cin>>x;
        ans.push_back(x);
    }
    cout<<"! ";
    for(int i : ans)
        cout<<i<<" ";
    cout<<endl;
    for(int i =1 ; i <= n; i++)
        f[i] = 0;
    for(int i = 1; i <= k; i++)
        v[i].clear();
    string pas;
    cin>>pas;
}
main(){
    int t;
    cin >> t;
    while(t--)
        solve();


}