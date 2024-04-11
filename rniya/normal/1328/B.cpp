#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,k,sum=0; cin >> n >> k;
        string ans="";
        for (int i=0;i<n;++i) ans+='a';
        for (int i=1;;++i){
            sum+=i;
            if (k<=sum){
                ans[n-1-i]='b';
                k-=sum-i;
                ans[n-k]='b';
                break;
            }
        }
        cout << ans << '\n';
    }
}