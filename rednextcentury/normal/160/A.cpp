# include <algorithm>
# include <iostream>
using namespace std;
int a[100000];
int main ()
{
    int n;
    cin>>n;
    int cur=0,sum=0;
    for (int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    sort(a,a+n);
    int num=0;
    for (int i=n-1;i>=0;i--)
    {
        num++;
        cur+=a[i];
        sum-=a[i];
        if (cur>sum)
        {
            cout<<num<<endl;
            return 0;
        }
    }
}