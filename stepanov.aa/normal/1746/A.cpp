#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define flt double
#define all(a) a.begin(), a.end()


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a;
        a.resize(n);
        int fnd = 0;
        for(int i = 0; i < n; i += 1){
            cin >> a[i];
            if(a[i] == 1){
                fnd = 1;
            }
        }
        if(!fnd){
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }       
    }
    return 0;
}