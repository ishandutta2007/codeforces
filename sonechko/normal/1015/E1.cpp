#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 200 + 11;
const int MOD = 1e9 + 7;

char b[N][N],a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    vector<int> xx,yy,tt;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='*')
    {
        int t=0;
        while (1)
        {
            t++;
            if (a[i-t][j]!='*'||a[i+t][j]!='*'||a[i][j-t]!='*'||a[i][j+t]!='*')
            {
                t--; break;
            }
            b[i-t][j]='*';
            b[i+t][j]='*';
            b[i][j-t]='*';
            b[i][j+t]='*';
        }
        if (t>0)
        {
            b[i][j]='*';
            xx.pb(i);
            yy.pb(j);
            tt.pb(t);
            //cout<<i<<" "<<j<<" "<<t<<endl;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='*'&&b[i][j]!='*')
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<xx.size()<<"\n";
    for (int j=0; j<xx.size(); j++)
        cout<<xx[j]<<" "<<yy[j]<<" "<<tt[j]<<"\n";
}