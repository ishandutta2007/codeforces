#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int first, sum=0;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            if (i==1)first=x;
            else sum+=x;
        }
        cout<<min(m,sum+first)<<endl;
    }
}