#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

bool use[N];
int num[N];
int n;
int a[N],b[N];

bool good(int x)
{
    for (int i=1; i<=n; i++)
        use[i]=0;
    for (int i=1; i<=n; i++)
        use[a[i]]=1;
    for (int i=1; i<=x; i++)
        use[b[i]]=1;
    int p=1;
    for (int i=x+1; i<=n; i++)
    {
        if (use[p]==0) return false;
        p++;
        if (p==n+1) break;
        use[b[i]]=1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]!=0) use[a[i]]=1;
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (b[i]!=0) num[b[i]]=i;
    }
    int t=b[n]+1,pos=0;
    for (int i=n; i>=1; i--)
        if (b[i]==0||b[i]!=t-1) {pos=i+1; break;} else t--;
    if (pos==0) {cout<<0<<endl; return 0;}
    if (b[pos]==1)
    {
        int t=b[n]+1;
        int c=0,res=0;
        for (int j=1; j<pos; j++)
        {
            if (use[t]==0) {c=1; break;}
            use[b[j]]=1;
            t++;
            res++;
            if (t==n+1) break;
        }
        if (c==0)
        {
            cout<<res<<endl;
            return 0;
        }
    }
    int l=0,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l+n<<"\n"; else cout<<r+n<<"\n";
}