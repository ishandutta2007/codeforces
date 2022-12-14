#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[1000][1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++)for (int j=1;j<=m;j++) a[i][j]='B';
        a[1][1]='W';
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)cout<<a[i][j];
            cout<<endl;
        }
    }
}