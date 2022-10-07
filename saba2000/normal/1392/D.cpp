#include<bits/stdc++.h>
using namespace std;
int a[300009];
int n;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >>n>> s;
        vector<int> v;
        for(int i = 0;i < n; i++)
            if(s[i] == 'R') a[i] = 1; else a[i] = 0;
        int k = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]) k++;
            else{
                v.push_back( k);
                k = 1;
            }
        }
        if(a[n-1] == a[0] && v.size()) v[0] += k;
        else v.push_back(k);
        int ans = 0;
        if(v.size() == 1) cout<<1+(n-1)/3<<endl; else{
        for(int x : v) ans += x/3;
        cout<<ans<<endl;
        }
    }


}