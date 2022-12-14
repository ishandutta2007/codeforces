#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        for (int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        ll sum=0;
        ll need=0;
        ll ret=0;
        for (int i=1;i<=n;i++){
            sum+=a[i];
            need+=x;
            if (sum>=need)ret=i;
        }
        cout<<ret<<endl;
    }
}