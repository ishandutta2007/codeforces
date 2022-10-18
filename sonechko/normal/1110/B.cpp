#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll b[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        b[0]=b[1];
        a[i]=b[i]-b[i-1]-1;
        if (i==1) a[i]++;
        ans+=a[i];
        ans++;
        //cout<<a[i]<<" ";
    }
    //cout<<ans<<endl;
    sort(a+1,a+n+1);
    int kol=k-1;
    for (int i=n; i>=n-kol+1; i--)
    ans-=a[i];
    cout<<ans<<endl;
}