#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,x;
        cin>>a>>b>>x;
        ll tot = a+b+x;
        tot=tot/2+1;
        if (a>=tot)cout<<x+1<<endl;
        else{
            if (a+x<tot)cout<<0<<endl;
            else {
                x-=tot-a;
                cout<<x+1<<endl;
            }
        }
    }
}