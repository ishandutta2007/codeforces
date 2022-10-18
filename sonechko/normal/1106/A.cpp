#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 11;

char a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    int ans=0;
    for (int i=2; i<n; i++)
    for (int j=2; j<n; j++)
    if (a[i][j]=='X'&&a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j-1]=='X'&&a[i+1][j+1]=='X')
    ans++;
    cout<<ans<<endl;
}