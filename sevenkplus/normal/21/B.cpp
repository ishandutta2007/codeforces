#include<cstdio>
#define EX() \
{\
    puts("0");\
    return 0;\
}
#define EY() \
{\
    puts("1");\
    return 0;\
}
#define EZ() \
{\
    puts("-1");\
    return 0;\
}
int main()
{
    int a1,b1,c1,a2,b2,c2;
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    if(!a1&&!b1&&c1)
        EX();
    if(!a2&&!b2&&c2)
        EX();
    if(!a1&&!b1&&!c1)
        EZ();
    if(!a2&&!b2&&!c2)
        EZ();
    if(a1*b2==a2*b1&&a1*c2==a2*c1)
        EZ();
    if(a1*b2==a2*b1)
        EX();
    EY();
    return 0;
}