# include <iostream>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (i!=a[i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n+1<<endl;
}