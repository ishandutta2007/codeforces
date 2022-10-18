#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;

int pr[N],ans[N];
map<int,int> pos;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=1;
    for (int i=1; i<=n; i++)
    {
        int g=pos[a[i]-1];
        ans[i]=ans[g]+1;
        pr[i]=g;
        pos[a[i]]=i;
        if (ans[i]>ans[l]) l=i;
    }
    cout<<ans[l]<<endl;
    vector<int> vv;
    while (l!=0)
    {
        vv.pb(l);
        l=pr[l];
    }
    for (int j=vv.size()-1; j>=0; j--)
        cout<<vv[j]<<" ";
    cout<<endl;
}