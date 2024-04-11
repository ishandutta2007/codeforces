#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 3e5 + 11;

pair<int,int> b[N];
int a[N],use[N],c[N];
vector<int> v[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    { cin>>a[i];
    b[i]=mp(a[i],i);
    }
    sort(b+1,b+n+1);
    for (int i=1; i<=n; i++)
        {
            a[b[i].ss]=i;
            c[i]=b[i].ss;
        }
    int kol=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        int d=i;
        kol++;
        v[kol].pb(d);
        use[d]=1;
        while (1==1)
        {
            if (a[d]==d) break;
            v[kol].pb(c[d]);
            use[c[d]]=1;
            int p=c[d];
            swap(a[c[d]],a[d]);
            d=p;
        }
    }
    cout<<kol<<endl;
    for (int i=1; i<=kol; i++)
    {
        sort(v[i].begin(),v[i].end());
        cout<<v[i].size()<<" ";
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

}