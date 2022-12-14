#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int b[1000000];
int ones[1000000];
int ms[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            ones[i]=ones[i-1]+(a[i]==1);
            ms[i]=ms[i-1]+(a[i]==-1);
        }
        bool can=1;

        for (int i=1;i<=n;i++)cin>>b[i];
        for (int i=n;i>=1;i--){

            if (a[i]<b[i])if (!ones[i-1]) can=0;
            if (a[i]>b[i])if (!ms[i-1])can=0;
        }
        if (can)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}