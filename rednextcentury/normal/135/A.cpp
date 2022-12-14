# include <iostream>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    bool p=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]>1)
        p=1;
    }
    sort(a,a+n);
    if (p)
    {
    cout<<1;
    for (int i=1;i<n;i++)
    {
        cout<<" "<<a[i-1];
    }
    }
    else
    {
        for (int i=0;i<n-1;i++)
        {
            cout<<1<<" ";
        }
        cout<<2<<endl;
    }
    cout<<endl;
}