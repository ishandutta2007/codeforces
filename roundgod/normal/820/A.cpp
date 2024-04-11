#include<bits/stdc++.h>
using namespace std;
int c,v0,v1,a,l;
int main()
{
    scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
    int s=0,d=v0-a;
    for(int i=1;;i++)
    {
        d+=a;
        if(d>=v1) d=v1;
        if(i==1) s+=d; else s+=d-l;
        if(s>=c)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}