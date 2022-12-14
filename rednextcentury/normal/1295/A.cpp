#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define mid (l+r)/2
//#define L (x<<1)
//#define R (L+1)
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if (n%2)cout<<7, n-=3;
        else cout<<1, n-=2;
        while(n){
            cout<<1;
            n-=2;
        }
        cout<<endl;
    }
}