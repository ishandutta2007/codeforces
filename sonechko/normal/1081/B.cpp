#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

vector<int> v[N];
int a[N];
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=n; i>=1; i--)
        v[a[i]].pb(i);
    int cc=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        cc++;
        int t=n-a[i];
        if (v[a[i]].size()<t) {cout<<"Impossible"<<endl; return 0;}
        for (int j=0; j<t; j++)
        {
            int x=v[a[i]].back();
            v[a[i]].pop_back();
            use[x]=cc;
        }
    }
    cout<<"Possible"<<endl;
    for (int i=1; i<=n; i++)
        cout<<use[i]<<" ";
    cout<<endl;
}