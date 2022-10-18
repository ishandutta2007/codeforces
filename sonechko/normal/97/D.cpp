#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 150 + 11;
const int MOD = 1e9 + 7;

bitset<N*N> a1,a2,b1,b2,c1,c2,d1,d2,noww,n1,n2;
int n,m;
char a[N][N];

int num(int l, int r)
{
    return (l-1)*m+r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int i1=0,j1=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='.'||a[i][j]=='E')
    {
        if (a[i-1][j]!='#') a1[num(i,j)]=1; else a2[num(i,j)]=1;
        if (a[i+1][j]!='#') b1[num(i,j)]=1; else b2[num(i,j)]=1;
        if (a[i][j-1]!='#') c1[num(i,j)]=1; else c2[num(i,j)]=1;
        if (a[i][j+1]!='#') d1[num(i,j)]=1; else d2[num(i,j)]=1;
        noww[num(i,j)]=1;
        if (a[i][j]=='E') {i1=i; j1=j;}
    }
    if (noww.count()==1) {cout<<0; return 0;}
    string s;
    cin>>s;
    s="."+s;
    for (int j=1; j<=k; j++)
    {
        if (s[j]=='U')
        {
            n1=(noww&a1);
            n2=(noww&a2);
            n1>>=m;
            noww=(n1|n2);
        } else
        if (s[j]=='D')
        {
            n1=(noww&b1);
            n2=(noww&b2);
            n1<<=m;
            noww=(n1|n2);
        } else
        if (s[j]=='L')
        {
            n1=(noww&c1);
            n2=(noww&c2);
            n1>>=1;
            noww=(n1|n2);
        } else
        {
            n1=(noww&d1);
            n2=(noww&d2);
            n1<<=1;
            noww=(n1|n2);
        }
        if (noww.count()==1&&noww[num(i1,j1)]==1)
        {
            cout<<j<<endl;
            return 0;
        }
    }
    cout<<-1;
}