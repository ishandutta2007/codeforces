#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 4e5 + 11;

int kk[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q,x;
    cin>>q>>x;
    int ans=0,nextt=0;
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        t%=x;
        kk[t]++;
        while (kk[nextt]>0)
        {
            kk[nextt]--;
            ans++;
            nextt++;
            if (nextt==x) nextt=0;
        }
        cout<<ans<<"\n";
    }
}