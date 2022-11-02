#include<cstdio>

using namespace std;

int num,ans,o;
char ch;

int main()
{
    ch=getchar();
    while(ch!=-1)
    {
        if(ch=='+')num++;
        else
            if(ch=='-')num--;
            else
            {
                while(ch!=':')ch=getchar();
                o=0;
                while(ch!='\n')ch=getchar(),o++;
                o--;
                ans+=o*num;
            }
        while(ch!='\n')ch=getchar();
        ch=getchar();
    }
    printf("%d\n",ans);
}