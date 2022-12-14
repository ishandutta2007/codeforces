#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int pen = a/c+((a%c)>0);
        int pencil= b/d+((b%d)>0);
        if (pen+pencil<=k)cout<<pen<<' '<<pencil<<endl;
        else cout<<-1<<endl;
    }
}