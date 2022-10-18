#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int k1[N],k2[N];
map<pair<int,int>,int> mt;

void up()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    mt.clear();
    mt[mp(0,0)]=0;
    int ans=-1;
    int l=-1,r=-1;
    for (int i=1; i<=n; i++)
    {
        k1[i]=k1[i-1];
        k2[i]=k2[i-1];
        if (s[i]=='L') k1[i]--; else
        if (s[i]=='R') k1[i]++; else
        if (s[i]=='U') k2[i]--; else k2[i]++;
        if (mt.find(mp(k1[i],k2[i]))!=mt.end())
        {
            int c=mt[mp(k1[i],k2[i])];
            if (ans==-1||ans>i-c)
            {
                ans=i-c;
                l=c+1;
                r=i;
            }
        }
        mt[mp(k1[i],k2[i])]=i;
    }
    if (ans==-1) cout<<ans<<"\n"; else cout<<l<<" "<<r<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}