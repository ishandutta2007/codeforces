#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 100 + 11;

char x[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int l=1,r=1;
    while (a>1)
    {
        x[l][r]='a';
        a--;
        r+=2;
        if (r>50) {l+=2; r=1;}
    }
    b--;
    for (int i=1; i<=l+1; i++)
    for (int j=1; j<=50; j++)
    if (x[i][j]!='a') x[i][j]='b';
    l+=2;
    for (int i=l; i<=50; i++)
    for (int j=1; j<=50; j++)
    {
        x[i][j]='a';
    }
    for (int i=l+1; i<=50; i+=2)
    for (int j=1; j<=50; j+=2)
    if (b>0) {b--; x[i][j]='b';} else
    if (c>0) {c--; x[i][j]='c';} else
    if (d>0) {d--; x[i][j]='d';}
    cout<<50<<" "<<50<<endl;
    for (int i=1; i<=50; i++)
    {for (int j=1; j<=50; j++)
    cout<<x[i][j];
    cout<<endl;
    }
}