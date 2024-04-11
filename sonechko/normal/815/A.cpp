#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 100 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
int a[N][N],b[N],c[N];
vector<string> v1,v3;
vector<int> v2,v4;
int ps;
void reee()
{
    cout<<ps<<"\n";
    for (int i=0; i<ps; i++)
        cout<<v3[i]<<" "<<v4[i]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    ps=1e9;
    for (int ii=0; ii<=501; ii++)
    {
        v1.clear();
        v2.clear();
        for (int p=1; p<=m; p++)
        if (a[1][p]<ii&&ps==(int)1e9) {cout<<-1<<endl; return 0;} else
        if (a[1][p]<ii)
        {
            reee();
            return 0;
        } else
        if (a[1][p]>ii)
        {
            int d=a[1][p];
            c[p]=0;
            while (d>ii)
            {
                d--;
                c[p]++;
                v1.pb("col");
                v2.pb(p);
            }
        } else c[p]=0;
        int pp=0;
        for (int i=1; i<=n; i++)
        {
            int d=a[i][1]-c[1];
            for (int j=1; j<=m; j++)
            if (a[i][j]-c[j]!=d) {pp=1; break;}
            if (d<0) pp=1;
            if (d>0)
            {
                for (int j=1; j<=d; j++)
                {
                    v1.pb("row");
                    v2.pb(i);
                }
            }
        }
        if (pp==0)
        {
            if (ps>v1.size())
            {
                ps=v1.size();
                v3=v1;
                v4=v2;
            }
        }
    }

}