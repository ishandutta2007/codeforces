#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
vector <ll> ans;

int main(){
    cin >> n;
    for (int i=1;i*i<=n;i++){
        if (n%i==0){
            ans.push_back(1ll*n*(i-1)/2+i);
        }
        if (n%i==0&&i*i<n){
            ans.push_back(1ll*n*(n/i-1)/2+n/i);
        }
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++) cout << ans[i] << ' '; cout << endl;
}