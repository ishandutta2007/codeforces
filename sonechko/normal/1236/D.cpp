#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
const ll MOD = 998244353;

map<int,bool> a[N];
vector<int> v1[N],v2[N];

void fnd(int l1, int l2, int r1, int r2)
{
    if (l1>l2||r1>r2) return;
    for (int l=l1; l<=l2; l++)
    for (int r=r1; r<=r2; r++)
    if (a[l][r]==0) {cout<<"No\n"; exit(0);}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(r);
        v2[r].pb(l);
        a[l][r]=1;
    }
    for (int i=1; i<=n; i++)
    {
        sort(v1[i].begin(),v1[i].end());
    }
    for (int i=1; i<=m; i++)
    {
        sort(v2[i].begin(),v2[i].end());
    }
    int l1=1,r1=1,l2=n,r2=m;
    int t=1;
    int ps=0;
    while (l1<=l2&&r1<=r2)
    {
        ///cout<<l1<<" "<<r1<<" -> "<<l2<<" "<<r2<<"  "<<t<<endl;
        ps++;
        if (t==1)
        {
            int l=0,r=v1[l1].size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (v1[l1][mid]>r1) r=mid; else l=mid;
            }
            int ps=r2+1;
            if (v1[l1].size()>0&&v1[l1][l]>r1) ps=min(ps,v1[l1][l]);
            if (v1[l1].size()>0&&v1[l1][r]>r1) ps=min(ps,v1[l1][r]);
            fnd(l1,l2,ps,r2);
            t=2;
            l1++;
            r2=ps-1;
            if (a[l1][r2]==1) {fnd(l1,l2,r1,r2); break;}
        } else
        if (t==2)
        {
            int l=0,r=v2[r2].size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (v2[r2][mid]>l1) r=mid; else l=mid;
            }
            int ps=l2+1;
            if (v2[r2].size()>0&&v2[r2][l]>l1) ps=min(ps,v2[r2][l]);
            if (v2[r2].size()>0&&v2[r2][r]>l1) ps=min(ps,v2[r2][r]);
            fnd(ps,l2,r1,r2);
            t=3;
            r2--;
            l2=ps-1;
            if (a[l2][r2]==1) {fnd(l1,l2,r1,r2); break;}
        } else
        if (t==3)
        {
            int l=0,r=v1[l2].size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (v1[l2][mid]<r2) l=mid; else r=mid;
            }
            int ps=r1-1;
            if (v1[l2].size()>0&&v1[l2][l]<r2) ps=max(ps,v1[l2][l]);
            if (v1[l2].size()>0&&v1[l2][r]<r2) ps=max(ps,v1[l2][r]);
            fnd(l1,l2,r1,ps);
            t=4;
            l2--;
            r1=ps+1;
            if (a[l2][r1]==1) {fnd(l1,l2,r1,r2); break;}
        } else
        {
            int l=0,r=v2[r1].size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (v2[r1][mid]<l2) l=mid; else r=mid;
            }
            int ps=l1-1;
            if (v2[r1].size()>0&&v2[r1][l]<l2) ps=max(ps,v2[r1][l]);
            if (v2[r1].size()>0&&v2[r1][r]<l2) ps=max(ps,v2[r1][r]);
            fnd(l1,ps,r1,r2);
            t=1;
            r1++;
            l1=ps+1;
            if (a[l1][r1]==1) {fnd(l1,l2,r1,r2);break;}
        }
    }
    ///cout<<ps<<"\n";
    cout<<"Yes\n";
}