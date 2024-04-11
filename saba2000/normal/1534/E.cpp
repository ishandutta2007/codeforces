#include<bits/stdc++.h>
using namespace std;
int f[2009], F[2009]; int n, k;
 bool check(){
     for(int i = 1; i <= n; i++)
        F[i] = f[i];
     while(1){
        vector<pair<int,int> > v;
        for(int i = 1; i <= n; i++)
            v.push_back({F[i], i});
        sort(v.rbegin(), v.rend());
        if(v[0].first == 0) return 1;
        if(v[k-1].first == 0) return 0;
        for(int i = 0; i < k; i++)
            F[v[i].second] --;
    }
 }
main(){
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
    if(k % 2 == 0 && n % 2 == 1){
         cout << -1 << endl;
         return 0;
    }
    for(int i = 1; i <= n; i++){
        f[i] = 1;
       
    }
    
    int K = k;
    if(k % 2 == 0) K /= 2;
    int j = 1;
    int t = 0;
    while((n + 2*t)%k){
        t++;
        f[t] += 2;
    }
    if(k == n-1)
        for(int i = 1; i <= n; i++)
            f[i] = k;
    int ans = 0;
    while(1){
 
 
        if(check()) break;
        for(int i0 = 0; i0 < K; i0++){
            t++;
            if(t == n+1) t = 1;
            f[t] += 2;
        }
    }
    while(1){
 
        vector<pair<int,int> > v;
        for(int i = 1; i <= n; i++)
            v.push_back({f[i], i});
        sort(v.rbegin(), v.rend());
        if(v[0].first == 0) break;
        cout<<"? ";
        for(int i = 0; i < k; i++)
            cout<<v[i].second<<" ",
            f[v[i].second] --;
        cout<<endl;
        int x;
        cin >> x;
        ans ^= x;
    }
    cout<<"! "<<ans<<endl;
}