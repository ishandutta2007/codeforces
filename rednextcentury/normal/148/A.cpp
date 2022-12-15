# include <algorithm>
# include <iostream>
using namespace std;
int a[4];
int main ()
{
    int n;
    for (int i=0;i<4;i++)cin>>a[i];
    cin>>n;
    int num=0;
    for (int i=1;i<=n;i++)
    {
        int c=0;
        for (int j=0;j<4;j++)
            if (i%a[j]==0)c=1;
        num+=c;
    }
    cout<<num<<endl;
}