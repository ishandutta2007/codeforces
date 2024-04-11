#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for (;T--;){
        int n,k; cin >> n >> k;
        vector<ll> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        vector<vector<int>> cnt(n,vector<int>(60,0));
        for (int i=0;i<n;++i){
            for (int j=0;j<60;++j){
                cnt[i][j]=a[i]%k;
                a[i]/=k;
            }
        }
        int ok=1;
        for (int j=0;j<60;++j){
            int sum=0;
            for (int i=0;i<n;++i){
                sum+=cnt[i][j];
            }
            if (1<sum) ok=0;
        }
        cout << (ok?"YES":"NO") << '\n';
    }
}