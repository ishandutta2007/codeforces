# include <iostream>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n,d;
    cin>>n>>d;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i!=j && max(a[i],a[j])-min(a[i],a[j])<=d) ans++;
        }
    }
    cout<<ans<<endl;
}