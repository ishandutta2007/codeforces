#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

int a[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<int> vv;
    for (int i=n; i>=1; i--)
    {
        if (use[a[i]]==0)
        {
            use[a[i]]=1;
            vv.pb(a[i]);
        }
    }
    cout<<vv.size()<<endl;
    for (int j=vv.size()-1; j>=0; j--)
        cout<<vv[j]<<" ";
    cout<<endl;
}