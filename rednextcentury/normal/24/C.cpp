#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
long long a[1000000][2];
int main()
{
    long long X=0,Y=0;
    long long n,j;
    cin>>n>>j;
    long long x,y;
    cin>>x>>y;
    long long Xneg=0,Yneg=0;
    long long Xpos=0,Ypos=0;
    bool pos=1;
    for (long long i=0;i<n;i++)cin>>a[i][0]>>a[i][1],a[i][0]*=2,a[i][1]*=2;
    for (long long i=n-1;i>=0;i--)
    {
        if (pos)
            Xpos+=a[i][0],Xneg-=a[i][0],Ypos+=a[i][1],Yneg-=a[i][1];
        else
            Xpos-=a[i][0],Xneg+=a[i][0],Ypos-=a[i][1],Yneg+=a[i][1];
        pos=!pos;
    }
    if (n%2==0)
    {
        long long k=(j-1)%n;
        long long h=(j-1)/n;
        pos=1;
        for (long long i=k;i>=0;i--)
        {
            if (pos)
                X+=a[i][0],Y+=a[i][1];
            else
                X-=a[i][0],Y-=a[i][1];
            pos=!pos;
        }
        if (pos) X+=Xpos*h,Y+=Ypos*h;
        else Y+=Xneg*h,Y+=Yneg*h;
        if (pos) X+=x,Y+=y;
        else X-=x,Y-=y;
    }
    else
    {
        long long k=(j-1)%n;
        long long h=(j-1)/n;
        pos=1;
        for (long long i=k;i>=0;i--)
        {
            if (pos)
                X+=a[i][0],Y+=a[i][1];
            else
                X-=a[i][0],Y-=a[i][1];
            pos=!pos;
        }
        h=h%2;
        if (pos) X+=Xpos*h,Y+=Ypos*h;
        else X+=Xneg*h,Y+=Yneg*h;
        if (h%2)
            pos=!pos;
        if (pos) X+=x,Y+=y;
        else X-=x,Y-=y;
    }
    cout<<X<<" "<<Y<<endl;
}