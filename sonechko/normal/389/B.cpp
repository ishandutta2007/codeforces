#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e3 + 11;
char a[N][N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];

    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (a[i][j]=='#')
    {
        if (a[i+1][j-1]=='#'&&a[i+1][j]=='#'
          &&a[i+1][j+1]=='#'&&a[i+2][j]=='#')
        {
            a[i][j]='.';
            a[i+1][j-1]='.';
            a[i+1][j]='.';
            a[i+1][j+1]='.';
            a[i+2][j]='.';
        } else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}