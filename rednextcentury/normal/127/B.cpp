# include  <iostream>
# include <algorithm>
using namespace std;
int a[100];
int main()
{
    int n,now;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>now;
        a[now-1]++;
    }
    long ans=0;
    for (int i=0;i<100;i++)
    {
        ans+=a[i]/2;
    
    
    
    }

    cout<<ans/2<<endl;







}