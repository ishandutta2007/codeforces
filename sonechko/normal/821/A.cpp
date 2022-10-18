#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ld long double
#define pb push_back
#define ff first
const int N = 100 + 11;
const int M = 1e9;
int a[N][N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (a[i][j]!=1)
    {
        int p=0;
        for (int k=1; k<=n; k++)
        for (int t=1; t<=n; t++)
        if (a[i][k]+a[t][j]==a[i][j]) {p=1;}
        if (p==0) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
    return 0;
}