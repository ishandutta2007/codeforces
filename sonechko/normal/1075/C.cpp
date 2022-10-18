#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

vector<int> vv;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    n++;
    a[n]=1000000000;
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
    {
        int x1,x2,y;
        cin>>x1>>x2>>y;
        if (x1==1) vv.pb(x2);
    }
    sort(vv.begin(),vv.end());
    int pos=-1;
    int ans=n+m;
    for (int i=1; i<=n; i++)
    {
        while (pos+1<vv.size()&&vv[pos+1]<a[i])
        pos++;
        ans=min(ans,i-1+(int)vv.size()-pos-1);
    }
    cout<<ans<<endl;
}