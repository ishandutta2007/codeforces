# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
int main()
{
    int a[4];
    for (int i=0;i<4;i++)
        cin>>a[i];
    sort(a,a+4);
    bool tr=0,seg=0;
    for (int i=2;i<4;i++)
    {
        if (a[i-1]+a[i-2]>a[i])
            tr=1;
        if (a[i-1]+a[i-2]==a[i])
            seg=1;
    }
    if (tr)
        cout<<"TRIANGLE"<<endl;
    else if (seg)
        cout<<"SEGMENT"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}