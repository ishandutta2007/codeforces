# include <iostream>
using namespace std;
int a[100000];
int main()
{
    int sum=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    int l=a[0],r=sum-a[0];
    int ans=0;
    for (int i=1;i<n;i++)
    {
        if (l==r)
            ans++;
        l+=a[i];
        r-=a[i];
    }
    cout<<ans<<endl;
}