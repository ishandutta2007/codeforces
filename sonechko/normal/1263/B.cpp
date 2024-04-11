#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N = 2e5 + 11;

string a[N];
map<string,int> mt;

void up()
{
    mt.clear();
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        mt[a[i]]++;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (mt[a[i]]==1) continue;
        mt[a[i]]--;
        int g=0;
        for (int p=0; p<4; p++)
        {
            for (int d=0; d<=9; d++)
        {
            string s=a[i];
            s[p]=char(d+'0');
            if (mt[s]==0) {a[i]=s; g=1; break;}
        }
        if (g==1) break;
        }
        mt[a[i]]++;
        ans++;
    }
    cout<<ans<<"\n";
    for (int i=1; i<=n; i++)
        cout<<a[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}