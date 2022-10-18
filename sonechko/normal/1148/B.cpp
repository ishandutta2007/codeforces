#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 5e5 + 11;

int n,m;
int a[N],b[N],p[N];

int kol(int x)
{
    int t=1;
    int ans=m,c=0;
    for (int i=1; i<=m; i++)
        if (b[i]<=x) c=i;
    ans=c;
    for (int i=1; i<=n; i++)
    {
        while (t<=c&&p[t]<=i)
            t++;
        ans=min(ans,i+(c-t+1));
    }
    ///cout<<x<<" - "<<ans<<endl;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=ta;
    }
    int pos=0;
    for (int i=1; i<=m; i++)
    {
        cin>>b[i];
        while (pos+1<=n&&a[pos+1]<=b[i])
            pos++;
        p[i]=pos;
    }
    int kk=k,pp=-1;
    for (int i=1; i<=m; i++)
        if (p[i]>0&&kk==0) {pp=i; break;} else
        if (p[i]>0) kk--;
    if (pp==-1) {cout<<-1<<endl; return 0;}
    int ans=b[pp];
    pos=0;
    for (int i=1; i<=min(n,k); i++)
    {
        while (pos+1<=m&&p[pos+1]<=i)
            pos++;
        if (pos+(k-i)+1>m) {cout<<-1<<endl; return 0;}
        ans=max(ans,b[pos+k-i+1]);
    }
    cout<<ans+tb<<endl;
}