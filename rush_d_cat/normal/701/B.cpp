#include<iostream>
using namespace std;
typedef __int64 ll;
int row[100000+2],col[100000+2];
ll r,c;
int main()
{
    ll n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        if(row[a]==0) r++;
        if(col[b]==0) c++;
        row[a]=1;col[b]=1;
        cout<<(n*n-(n*r+n*c-r*c));
        if(i!=m) cout<<" ";
    }
    return 0;
}