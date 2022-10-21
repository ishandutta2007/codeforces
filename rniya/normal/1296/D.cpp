#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b,k; cin >> n >> a >> b >> k;
    vector<int> use(n);
    for (int i=0;i<n;++i){
        int h; cin >> h; h%=a+b;
        if (!h) h+=a+b;
        use[i]=(h-1)/a;
    }
    sort(use.begin(),use.end());
    int ans=0,sum=0;
    for (int i=0;i<n;++i) if (sum+use[i]<=k){
        sum+=use[i]; ++ans;
    }
    cout << ans << '\n';
}