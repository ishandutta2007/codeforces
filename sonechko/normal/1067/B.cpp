#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N];
int dist,kor,prr[N];
bool use[N];

void dfs(int l, int d, int pr)
{
    if (d>dist)
    {
        dist=d;
        kor=l;
    }
    prr[l]=pr;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],d+1,l);
}

void dfss(int l, int k)
{
    use[l]=1;
    if (k==0&&v[l].size()!=1) {cout<<"No"<<endl; exit(0);}
    if (k==0) return;
    int kk=0;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) kk++;
    if (kk<3) {cout<<"No"<<endl; exit(0);}
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfss(v[l][j],k-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    kor=1;
    dist=0;
    dfs(1,0,0);
    int p=kor;
    kor=1;
    dist=0;
    dfs(p,0,0);
    if (dist!=k*2) {cout<<"No"<<endl; return 0;}
    for (int t=1; t<=k; t++)
    {
        kor=prr[kor];
    }
    dfss(kor,k);
    cout<<"Yes"<<endl;
}