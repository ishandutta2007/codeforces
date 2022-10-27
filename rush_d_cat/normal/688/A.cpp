#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char c;
    int n,d;cin>>n>>d;
    int cnt=0,ans=0;
    for(int i=1;i<=d;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
        {
            cin>>c;
            if(c=='0') flag=0;
        }
        if(!flag) cnt++;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}