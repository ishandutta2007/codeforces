#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        int sum=0,odd=0,even=0;
        for (int i=0;i<n;++i){
            sum+=a[i];
            (a[i]&1?odd:even)=1;
        }
        cout << (sum&1||(odd&&even)?"YES":"NO") << '\n';
    }
}