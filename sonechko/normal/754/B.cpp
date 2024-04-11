#include<bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 11;
char a[N][N];
void good(char l, char r, char k)
{
    int k1=0,k2=0;
    if (l=='x') k1++;
    if (l=='.') k2++;
    l=r;
    if (l=='x') k1++;
    if (l=='.') k2++;
    l=k;
    if (l=='x') k1++;
    if (l=='.') k2++;
    if (k1==2&&k2==1) {cout<<"YES"<<endl; exit(0);}
}
int main()
{
    for (int i=1; i<=4; i++)
        for (int j=1; j<=4; j++)
        cin>>a[i][j];
    for (int i=1; i<=4; i++)
    {
        good(a[i][1],a[i][2],a[i][3]);
        good(a[1][i],a[2][i],a[3][i]);
        good(a[i][4],a[i][2],a[i][3]);
        good(a[4][i],a[2][i],a[3][i]);
    }
    for (int i=1; i<=2; i++)
    for (int j=1; j<=2; j++)
    {
        good(a[i][j],a[i+1][j+1],a[i+2][j+2]);
    }
    for (int i=1; i<=2; i++)
    for (int j=3; j<=4; j++)
    {
        good(a[i][j],a[i+1][j-1],a[i+2][j-2]);
    }
    cout<<"NO"<<endl;
}