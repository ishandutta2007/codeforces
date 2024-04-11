#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[100][100];
int row[100];
int col[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int cnt=0;
        for (int i=0;i<n;i++)row[i]=0;
        for (int i=0;i<m;i++)col[i]=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin>>a[i][j];
                if (a[i][j]=='A')row[i]++,col[j]++,cnt++;
            }
        }
        bool corner = (a[0][0]=='A' || a[n-1][0]=='A' || a[0][m-1]=='A' || a[n-1][m-1]=='A');
        bool line = 0;
        for (int i=0;i<n;i++)if (row[i]==m)line=1;
        for (int i=0;i<m;i++)if (col[i]==n)line=1;

        if (cnt==0) {
            cout<<"MORTAL\n";
        } else if (cnt==n*m){
            cout<<"0\n";
        } else if (row[0]==m || row[n-1]==m || col[0]==n || col[m-1]==n) {
            cout<<"1\n";
        } else if (corner || line){
            cout<<"2\n";
        } else if (row[0]||row[n-1]||col[0]||col[m-1]){
            cout<<"3\n";
        } else {
            cout<<"4\n";
        }
    }
}