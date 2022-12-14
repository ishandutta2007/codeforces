#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int ret=0;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            if (i==0){ret+=x;continue;}
            int cost = i;
            int mx = d / cost;
            if (mx>=x){
                ret+=x;
                d -= x*cost;
            } else {
                ret+=mx;
                d-=mx*cost;
            }
        }
        cout<<ret<<endl;
    }
}