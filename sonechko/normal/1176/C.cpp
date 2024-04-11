#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 5e5 + 11;

int a[N];
vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==4) a[i]=1; else
        if (a[i]==8) a[i]=2; else
        if (a[i]==15) a[i]=3; else
        if (a[i]==16) a[i]=4; else
        if (a[i]==23) a[i]=5; else a[i]=6;
        v[a[i]].pb(i);
    }
    for (int i=2; i<=6; i++)
        reverse(v[i].begin(),v[i].end());
    int ans=0;
    for (int j=0; j<v[1].size(); j++)
    {
        int pos=v[1][j];
        for (int j=2; j<=6; j++)
        {
            while (v[j].size()>0&&v[j].back()<=pos)
                v[j].pop_back();
            if (v[j].size()==0) {pos=-1; break;}
            pos=v[j].back();
        }
        if (pos==-1) break;
        ans++;
        for (int j=2; j<=6; j++)
            v[j].pop_back();
    }
    cout<<n-(ans*6)<<endl;
}