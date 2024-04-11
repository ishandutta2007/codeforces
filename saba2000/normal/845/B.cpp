#include<bits/stdc++.h>
using namespace std;
main()
{
    char a[6];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    sort(a,a+3);
    sort(a+3,a+6);
    if(a[0]+a[1]+a[2]>a[3]+a[4]+a[5])
    {
        swap(a[0],a[3]);
        swap(a[1],a[4]);
        swap(a[2],a[5]);
    }
    int d=a[3]+a[4]+a[5]-a[0]-a[1]-a[2];
    //cout<<d<<endl;
    for (int i=0; i<3; i++)
       a[i]='9'-a[i];
for (int i=3; i<6; i++)
a[i]=a[i]-'0';
    sort(a,a+6);
    reverse(a,a+6);

    if(d==0) cout<<0<<endl;
    else
    {
        for (int i=0; i<6; i++)
        {

        if(a[i]>=d) {cout<<i+1<<endl; return 0;}
        else d-=a[i];

        }
    }

}