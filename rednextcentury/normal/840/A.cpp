#include<bits/stdc++.h>
using namespace std;
pair<int,int> b[1000000];
int a[1000000];
int m;
pair<int,int> ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>a[i];
    for (int j=0;j<m;j++)
        cin>>b[j].first,b[j].second=j;
    sort(b,b+m);
    sort(a,a+m);
    reverse(a,a+m);
    for (int i=0;i<m;i++)
    {
        ret[i].first=b[i].second;
        ret[i].second=a[i];
    }
    sort(ret,ret+m);
    for (int i=0;i<m;i++)
        cout<<ret[i].second<<' ';
    cout<<endl;
}