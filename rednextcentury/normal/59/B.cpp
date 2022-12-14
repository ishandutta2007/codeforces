

# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int m=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x%2)
            a[m++]=x;
        else
            sum+=x;
    }
    sort(a,a+m);
    int s;
    if (m%2)
        s=0;
    else
        s=1;
    for (int i=s;i<m;i++)
        sum+=a[i];
    if (sum%2)
        cout<<sum<<endl;
    else
        cout<<0<<endl;
}