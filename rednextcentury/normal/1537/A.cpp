#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for (int i=0;i<n;i++) {
            int x;
            cin>>x;
            sum+=x;
        }
        if (sum < n) cout<<1<<endl;
        else if (sum==n) cout<<0<<endl;
        else cout<<sum-n<<endl;
    }
}