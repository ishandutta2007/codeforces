#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N],s[N];
map<ll,int> mt;
int d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    mt[0]=0;
    for (int i=1; i<=n; i++)
        d[i]=n+1;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if (mt.find(s[i])!=mt.end())
        {
            int pos=mt[s[i]];
            d[pos+1]=min(d[pos+1],i);
        }
        mt[s[i]]=i;
    }
    multiset<int> stt;
    stt.insert(n+1);
    int r=0;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        while (r+1<*stt.begin()&&r+1<d[r+1])
        {
            r++;
            stt.insert(d[r]);
        }
        if (r>=i)
        {
            ans+=1ll*(r-i+1);
            stt.erase(stt.find(d[i]));
        } else
        {
            r=i;
        }
    }
    cout<<ans<<"\n";
}