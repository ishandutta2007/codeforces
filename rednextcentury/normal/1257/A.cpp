#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,a,b,x;
        cin>>n>>x>>a>>b;
        int ret = min(n-1,abs(a-b)+x);
        cout<<ret<<endl;
    }
}