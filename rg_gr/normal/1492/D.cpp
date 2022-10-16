#include <stdio.h>
#include <string.h>
#include <algorithm>
inline int read()
{
    int num=0;char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num;
}
signed main()
{
    int b=read(),a=read(),k=read();
    //for(int b=0;b<=6;b++)for(int a=1;a<=6;a++)for(int k=0;k<=a+b;k++){
    if(b<k)
    {
        if(a+b-k<=1||b==0)puts("No");
        else
        {
            //dui qi n wei hu ichuxian 
            // 1 d ges hu shi a+b-k
            puts("Yes");
            for(int i=0;i<a+b-k;i++)putchar(49);
;           //fang k-b ge 1 zai hou mian
            for(int i=1;i<b;i++)putchar(48);
            for(int i=1;i<=k-b;i++)putchar(49);//
            puts("0");
            for(int i=1;i<a+b-k;i++)putchar(49);
            for(int i=1;i<=b;i++)putchar(48);
            for(int i=1;i<=k-b;i++)putchar(49);//
            puts("1");
        }
    }
    else
    {
        if(a==1)
        {
            if(k)puts("No");
            else
            {
                puts("Yes");
                putchar(49);
                for(int i=1;i<a+b;i++)putchar(48);puts("");
                putchar(49);
                for(int i=1;i<a+b;i++)putchar(48);puts("");
            }
            return 0;
        }
        puts("Yes");
        int t=a+b-b+k;
        for(int i=0;i<a;i++)putchar(49);
        for(int i=0;i<b;i++)putchar(48);
        puts("");
        for(int i=0;i<a-1;i++)putchar(49);
        for(int i=a;i<=a+b;i++)putchar((i==t)+48);
        puts("");
    }

    //}
}