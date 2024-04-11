# include <iostream>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    int s,g;
    cin>>s>>g;
    int ans=0;
    for (int i=s;i<g;i++)
    ans+=a[i];
    cout<<ans<<endl;
}