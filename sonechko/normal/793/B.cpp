#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 1e3 + 11;

char a[N][N];
int sum1[N][N],sum2[N][N];
int ss(int l1, int r1, int l2, int r2)
{
    if (l1==l2)
    {
        if (r1>r2) swap(r1,r2);
        return sum2[l1][r2]-sum2[l1][r1-1];
    }
    if (r1!=r2) {return 100;}
    if (l1>l2) swap(l1,l2);
    return sum1[l2][r1]-sum1[l1-1][r1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l1,r1,l2,r2;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='S') {l1=i; r1=j;}
        if (a[i][j]=='T') {l2=i; r2=j;}
        sum1[i][j]=sum1[i-1][j];
        sum2[i][j]=sum2[i][j-1];
        if (a[i][j]=='*') {sum1[i][j]++; sum2[i][j]++;}
    }
    for (int k1=1; k1<=m; k1++)
    if (ss(l1,k1,l1,r1)==0)
    {
        if (l1==l2&&r2==k1) {cout<<"YES"<<endl; return 0;}
        for (int k2=1; k2<=n; k2++)
            if (ss(l1,k1,k2,k1)==0&&ss(l2,r2,k2,k1)==0)
            {
                cout<<"YES"<<endl; return 0;
            }
    }

    for (int k1=1; k1<=n; k1++)
    if (ss(l1,r1,k1,r1)==0)
    {
        if (l2==k1&&r2==r1) {cout<<"YES"<<endl; return 0;}
        for (int k2=1; k2<=m; k2++)
            if (ss(k1,r1,k1,k2)==0&&ss(k1,k2,l2,r2)==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}