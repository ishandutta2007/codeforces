#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int oneLeft = n - (k-1);
        if (oneLeft>0 && oneLeft%2){
            cout<<"YES"<<endl;
            for (int i=0;i<k-1;i++)cout<<1<<' ';
            cout<<oneLeft<<endl;
            continue;
        }
        int twoLeft = n - (k-1)*2;
        if (twoLeft>0 && twoLeft%2==0){
            cout<<"YES"<<endl;
            for (int i=0;i<k-1;i++)cout<<2<<' ';
            cout<<twoLeft<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}