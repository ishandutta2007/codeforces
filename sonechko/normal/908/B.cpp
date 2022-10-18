#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 100 + 11;

string s;
char a[N][N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l1=0,r1=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='S') {l1=i; r1=j;}
    }
    string s;
    cin>>s;
    int ans=0;
    for (int p=0; p<=3; p++)
    for (int d=0; d<=3; d++)
    for (int c=0; c<=3; c++)
    for (int k=0; k<=3; k++)
    if (p!=d&&p!=c&&p!=k&&c!=d&&c!=k&&d!=k)
    {
        int l=l1,r=r1;
        int g=0;
        for (int j=0; j<s.size(); j++)
        {
            int nn=0;
            if (s[j]=='0') nn=p;
            if (s[j]=='1') nn=d;
            if (s[j]=='2') nn=c;
            if (s[j]=='3') nn=k;
            if (nn==0) l--;
            if (nn==1) l++;
            if (nn==2) r--;
            if (nn==3) r++;
            if (l<1||r<1||l>n||r>m||a[l][r]=='#') break;
            if (a[l][r]=='E') {g=1; break;}
        }
        if (g==1) ans++;
    }
    cout<<ans<<endl;
}