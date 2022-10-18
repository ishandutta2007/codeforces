#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int a[N],kol[N];
vector<int> v[N];
int n,k,t;
vector<pair<int,int> > vv;

void dfs(int l, int kol, int dep)
{
    if (dep==0) return;
    while (t<n&&kol<k)
    {
        t++;
        kol++;
        vv.pb(mp(t,l));
        dfs(t,1,dep-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d;
    cin>>n>>d>>k;
    if (d>n-1||n==1) {cout<<"NO"<<endl; return 0;}
    if (d==1&&n==2) {cout<<"YES"<<endl<<1<<" "<<2<<endl; return 0;}
    if (k<2) {cout<<"NO"<<endl; return 0;}
    t=d+1;
    for (int i=2; i<=d; i++)
    {
        vv.pb(mp(i-1,i));
        int kol=max(i-1,d+1-i);
        kol=d-kol;
        dfs(i,2,kol);
    }
    vv.pb(mp(d,d+1));
    if (t<n) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ff<<" "<<vv[j].ss<<"\n";
}

/**         |
       111  1  1
       |||  |
    1   2   2
    |   |   |
1 - 4 - 2 - 2 - 2 - 2 - 1
    |
    1
**/