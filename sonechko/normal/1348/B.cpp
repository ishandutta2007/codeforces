#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int a[N],b[N];
int use[N];

void up()
{
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        use[i]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        use[a[i]]=1;
    }
    int m=0;
    for (int i=1; i<=n; i++)
        if (use[i]==1) {m++; b[m]=i;}
    if (m>k) {cout<<"-1\n"; return;}
    for (int i=1; i<=n; i++)
        if (m<k)
    {
        m++;
        b[m]=a[i];
    } else
    {
        int pos=-1;
        for (int j=m-k+1; j<=m; j++)
            if (b[j]==a[i]) {pos=j; break;}
        int t=m-k+1;
        for (int j=t; j<pos; j++)
        {
            m++;
            b[m]=b[j];
        }
        m++;
        b[m]=a[i];
    }
    cout<<m<<"\n";
    for (int i=1; i<=m; i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
    }
}