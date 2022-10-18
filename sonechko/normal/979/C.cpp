#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
#define ll long long
const int N = 4e5 + 11;
const int MOD = 1e9 + 9;

vector<int> v[N];
int x,y,kk;
bool use[N];


void dfs(int l)
{
          use[l]=1;
          kk++;
          for (int j=0; j<v[l].size(); j++)
          if (use[v[l][j]]==0) dfs(v[l][j]);
          
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>x>>y;
    for (int i=1; i<n; i++)
    {
              int l,r;
              cin>>l>>r;
              v[l].pb(r);
              v[r].pb(l);
    }
    int p1=n,p2=n;
    use[x]=1;
    for (int j=0; j<v[x].size(); j++)
    {
             kk=0;
             dfs(v[x][j]);
             if (use[y]==1) {p1-=kk; break;}
    }
    for (int i=1; i<=n; i++)
    use[i]=0;
    use[y]=1;
    for (int j=0; j<v[y].size(); j++)
    {
              kk=0;
              dfs(v[y][j]);
              if (use[x]==1) {p2-=kk; break;}
    }
    cout<<n*1ll*(n-1)-p1*1ll*p2<<endl;
}