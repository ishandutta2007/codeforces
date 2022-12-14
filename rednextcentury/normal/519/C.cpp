# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    while(1)
    {
        if (n+m<3 || n==0 || m==0)
            break;
        if (n>m)
            n-=2,m-=1,ans++;
        else
            m-=2,n-=1,ans++;
    }
    cout<<ans<<endl;
}