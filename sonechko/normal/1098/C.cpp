#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int n;
ll s;

ll dfs(int n, int x)
{
    ll ans=1ll*n;
    n--;
    int t=n/x,p=n%x;
    for (int j=1; j<=x; j++)
    {
        int kol=t;
        if (p>0) {p--; kol++;}
        if (kol==0) break;
        ans+=dfs(kol,x);
    }
    return ans;
}

inline ll get_min(int x)
{
    return dfs(n,x);
}

inline bool good(int x)
{
    ll t=get_min(x);
    if (t>s) return false;
    return true;
}

int c;
set<int> v[N];
int deep[N],pp[N];

void update_min(int num, int n, int x)
{
    n--;
    int t=n/x,p=n%x;
    for (int j=1; j<=x; j++)
    {
        int kol=t;
        if (p>0) {p--; kol++;}
        if (kol==0) break;
        c++;
        v[num].insert(c);
        deep[c]=deep[num]+1;
        pp[c]=num;
        update_min(c,kol,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>s;
    c=0;
    for (int j=1; j<=n; j++)
    {
        v[j].clear();
        deep[j]=0;
        pp[j]=0;
    }
    int l=1,r=n-1;
    if (s>n*1ll*(n+1)/2ll||s<n*2-1) {cout<<"No"<<endl; return 0;}
    if (s==n*1ll*(n+1)/2ll)
    {
        cout<<"Yes"<<endl;
        for (int i=2; i<=n; i++)
            cout<<i-1<<" ";
        cout<<endl;
        return 0;
    }
    //for (int i=1; i<=n; i++)
    //    cout<<i<<" - "<<get_min(i)<<endl;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) r=l;
    r--;
    c=1;
    update_min(1,n,r);
    set<pair<int,int> > st;
    for (int i=1; i<=n; i++)
        st.insert(mp(deep[i],i));
    ll ans=get_min(r);
    while (ans!=s)
    {
        pair<int,int> p1=*st.begin(),p2=*st.rbegin();
        int l1=p1.ss,l2=p2.ss;
        //cout<<l1<<" "<<l2<<" "<<deep[l2]-deep[l1]-1<<" "<<ans-s<<endl;
        //if (deep[l2]-deep[l1]-1==0) return 0;
        if (deep[l2]-deep[l1]-1>ans-s)
        {
            for (int i=1; i<=n; i++)
                if (v[i].size()<r+1&&deep[l2]-deep[i]-1==ans-s)
            {
                v[pp[l2]].erase(l2);
                v[i].insert(l2);
                pp[l2]=i;
                ans-=1ll*(deep[l2]-deep[i]-1);
                break;
            }
        } else
        {
            v[pp[l2]].erase(l2);
            v[l1].insert(l2);
            ans-=1ll*(deep[l2]-deep[l1]-1);
            st.erase(mp(deep[l2],l2));
            deep[l2]=deep[l1]+1;
            pp[l2]=l1;
            st.insert(mp(deep[l2],l2));
            if ((int)v[l1].size()==r+1) st.erase(mp(deep[l1],l1));
        }
    }
    cout<<"Yes"<<endl;
    for (int i=2; i<=n; i++)
        cout<<pp[i]<<" ";
    cout<<endl;

}