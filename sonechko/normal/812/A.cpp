#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
int a[5][5];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=4; i>=1; i--)
    for (int j=1; j<=4; j++)
    cin>>a[i][j];
    if (a[1][4]==1&&(a[1][1]+a[1][2]+a[1][3]+a[2][3]+a[3][2]+a[4][1]>0))
    cout<<"YES"<<endl; else
    if (a[2][4]==1&&(a[2][1]+a[2][2]+a[2][3]+a[3][3]+a[4][2]+a[1][1]>0))
    cout<<"YES"<<endl; else
    if (a[3][4]==1&&(a[3][1]+a[3][2]+a[3][3]+a[4][3]+a[1][2]+a[2][1]>0))
    cout<<"YES"<<endl; else
    if (a[4][4]==1&&(a[4][1]+a[4][2]+a[4][3]+a[1][3]+a[2][2]+a[3][1]>0))
    cout<<"YES"<<endl; else
    cout<<"NO"<<endl;
}