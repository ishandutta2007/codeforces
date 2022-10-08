#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void get(int &a)
{
    int x,y;
    char z;
    string s;
    getline(cin,s);
    scanf("[%d:%d %c.m.]:",&x,&y,&z);
    x%=12;
    if(z=='p')
        x+=12;
    a=x*60+y;
}
int main()
{
    int s=0,t,la=1500,a,r=0;
    for(scanf("%d",&t);t--;)
    {
        get(a);
        if(a==la)
            if(r>8)
                s++,r=0;
            else
                r++;
        else
            s+=a<la,r=0;
        la=a;
    }
    printf("%d\n",s);
    return 0;
}