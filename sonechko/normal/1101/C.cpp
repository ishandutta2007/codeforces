#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

pair<pair<int,int>,int> a[N];
int ans[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ans[i]=-1;
        cin>>a[i].ff.ff>>a[i].ff.ss;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    int r=a[1].ff.ss;
    ans[a[1].ss]=1;
    int p=0;
    for (int i=2; i<=n; i++)
    {
        int l1=a[i].ff.ff,r1=a[i].ff.ss;
        if (l1<=r)
        {
            ans[a[i].ss]=1;
            r=max(r,r1);
        } else 
        {
            ans[a[i].ss]=2;
            p=1;
        }
    }
    if (p==0) {cout<<-1<<"\n"; return;}
    for (int i=1; i<=n; i++)
    cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        up();
    }
}