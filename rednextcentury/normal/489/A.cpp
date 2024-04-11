# include <iostream>
# include <cmath>
# include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000];
int b[10000];
/*void print(int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}*/
int main ()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b,b+n);
    cout<<n<<endl;
    int l=n;
    for (int i=0;i<n;i++)
    {
        for (int x=i+1;x<n;x++)
        {
            if (a[x]==b[i])
            {
                cout<<i<<" "<<x<<endl;
                l--;
                swap(a[i],a[x]);
                break;
            }
        }
    }
    while(l>0)
    {
        cout<<"0 0"<<endl;
        l--;
    }

}