#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int d1[N],d2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    int ans=0;
    int nn=n;
    n-=a1*(k1-1);
    n-=a2*(k2-1);
    ans=max(0,n);
    cout<<ans<<" ";
    n=nn;
    ans=0;
    if (k1<k2)
    {
        int p=min(a1,n/k1);
        ans+=p;
        n-=p*k1;
        p=min(a2,n/k2);
        ans+=p;
        cout<<ans<<endl;
    } else
    {
        int p=min(a2,n/k2);
        ans+=p;
        n-=p*k2;
        p=min(a1,n/k1);
        ans+=p;
        cout<<ans<<endl;
    }
}