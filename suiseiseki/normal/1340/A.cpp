#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i++) {
        if(arr[i]-arr[i-1]>=2) {
            cout<<"No"<<endl;
            return ;
        }
    }
    cout<<"Yes"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}