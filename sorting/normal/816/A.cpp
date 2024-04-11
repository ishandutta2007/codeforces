#include<iostream>
#include<stdio.h>

using namespace std;

int reverse_(int x)
{
    return x/10+(x%10)*10;
}

int main ()
{
    int h,m,i=0;

    scanf("%d:%d",&h,&m);

    while(reverse_(h)!=m)
    {
        i++;
        m++;
        if(m==60)
        {
            m=0;
            h++;
            if(h==24)h=0;
        }
    }

    cout<<i<<endl;

    return 0;
}