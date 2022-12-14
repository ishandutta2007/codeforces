#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        p=2*n+p;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (p)cout<<i<<' '<<j<<endl, p--;
            }
        }
    }
}