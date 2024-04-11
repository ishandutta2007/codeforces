#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast
    int n;
    cin>>n;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    int m;
    cin>>m;
    int ret=1000000000;
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        if (l>=sum)
            ret=min(ret,l);
        else if (r>=sum && l<=sum)
            ret=min(ret,sum);
    }
    if (ret==1000000000)
        cout<<-1<<endl;
    else cout<<ret<<endl;
}