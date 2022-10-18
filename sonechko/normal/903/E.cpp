#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define ld long double
const ll N = 5000 + 11;
int pp[N][N],kol[N],kol1[N];
string a[N];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        s="."+s;
        a[i]=s;
    }
    string s=a[1];
    for (int i=1; i<=m; i++)
        kol[s[i]-'a']++;
    int kk=0;
    for (int i=0; i<=26; i++)
        kk=max(kk,kol[i]);
    for (int i=2; i<=n; i++)
    {
        string t=a[i];
        for (int j=0; j<=26; j++)
            kol1[j]=0;
        for (int j=1; j<=m; j++)
        {
            kol1[t[j]-'a']++;
        }
        for (int j=0; j<=26; j++)
        if (kol1[j]!=kol[j]) {cout<<"-1"<<endl; return 0;}
        for (int j=1; j<=m; j++)
            if (t[j]!=s[j]) pp[i][j]=pp[i][j-1]+1; else pp[i][j]=pp[i][j-1];
    }
    for (int l=1; l<=m; l++)
    for (int r=l+1; r<=m; r++)
    {
        int xx=0;
        for (int i=2; i<=n; i++)
        {
            int p=0;
            p+=pp[i][l-1];
            p+=pp[i][r-1]-pp[i][l];
            p+=pp[i][m]-pp[i][r];
            if (a[1][r]!=a[i][l]) p++;
            if (a[1][l]!=a[i][r]) p++;
            if (p!=2&&p!=0) xx=1;
            if (p==0&&kk==1) xx=1;
        }
        if (xx==0)
        {
            for (int i=1; i<l; i++)
                cout<<a[1][i];
            cout<<a[1][r];
            for (int i=l+1; i<r; i++)
                cout<<a[1][i];
            cout<<a[1][l];
            for (int i=r+1; i<=m; i++)
                cout<<a[1][i];
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}