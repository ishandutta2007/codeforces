#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; string S; cin >> n >> S;
        string ans=S; int k=1;
        for (int i=0;i<n-1;++i){
            string check="";
            for (int j=i+1;j<n;++j) check+=S[j];
            for (int j=0;j<=i;++j) check+=S[((n-i)&1?j:i-j)];
            if (check<ans) ans=check,k=i+2;
        }
        cout << ans << '\n';
        cout << k << '\n';
    }
}