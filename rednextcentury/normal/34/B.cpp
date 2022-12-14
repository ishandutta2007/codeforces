
# include <iostream>
# include <string>
# include <algorithm>
#define EPS 1e-9
using namespace std;
int a[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int i=0;
    int ans=0;
    while(a[i]<0 && i<n && i<m)
        ans+=-a[i],i++;
    cout<<ans<<endl;
}