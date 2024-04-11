#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k,s;
    cin>>n>>k>>s;
    if ((n-1)*k<s||k>s) {cout<<"NO"<<endl; return 0;}
    int pos=1;
    cout<<"YES"<<endl;
    for (int d=1; d<=k; d++)
    {
        if ((k-d)>(s-(n-1)))
        {
            for (int t=1; t<=n; t++)
                if (k-d==s-t)
            {
                if (pos-t>=1) pos-=t; else pos+=t;
                s-=t;
                break;
            }
        } else
        {
            if (pos==1) pos=n; else pos=1;
            s-=n-1;
        }
        cout<<pos<<" ";
    }
    cout<<endl;
}