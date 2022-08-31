#include<stdio.h>
using namespace std;
int main()
{
    char x1,x2,x3,x4,x5,x6;long sh,sm,th,tm;
    scanf("%c%c%c%c%c%c",&x1,&x2,&x3,&x4,&x5,&x6);sh=(x1-48)*10+(x2-48);sm=(x4-48)*10+(x5-48);
    scanf("%c%c%c%c%c",&x1,&x2,&x3,&x4,&x5);th=(x1-48)*10+(x2-48);tm=(x4-48)*10+(x5-48);
    if(th*60+tm>sh*60+sm)sh+=24;long sth,stm;long c=sh*60+sm-th*60-tm;sth=c/60;stm=c%60;
    printf("%ld%ld:%ld%ld",sth/10,sth%10,stm/10,stm%10);
    //for(;;);
    return 0;
}