# include <iostream>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=1000000000;
    int id1,id2;
    for (int i=0;i<n;i++)
    {
        int j=i+1;
        if (j==n)
            j=0;
        if (i!=j && max(a[i],a[j])-min(a[i],a[j])< ans) ans=max(a[i],a[j])-min(a[i],a[j]),id1=i+1,id2=j+1;
    }
    cout<<id1<<" "<<id2<<endl;
}