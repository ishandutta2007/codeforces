#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int b,p,f,h,c;
        cin>>b>>p>>f>>h>>c;
        int ans=0;
        for (int t=0; t<=100; t++)
            if (t*2<=b&&t<=p) ans=max(ans,h*t+min((b-t*2)/2,f)*c);
        cout<<ans<<"\n";
    }
}
/**
8
1 1 1 1 210 140 84 60
**/