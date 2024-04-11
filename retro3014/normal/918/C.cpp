#include <stdio.h>
#include <string.h>

int N;
char c[10000];

int main()
{
    scanf("%s", c);
    N=(int)strlen(c);
    int a, b;
    int cnt=0;
    int t;
    for(int i=0; i<N; i++)
    {
        a=0;
        b=0;
        t=0;
        for(int j=i; j<N; j++)
        {
            if(b>a+t)
            {
                break;
            }
            if(c[j]=='(')
            {
                a++;
            }
            else if(c[j]==')')
            {
                b++;
            }
            else
            {
                t++;
            }
            while(b+t>a)
            {
                t--;
                a++;
            }
            if(b>a+t)
            {
                break;
            }
            if((j-i+1)%2==0)
            {
                if(a-b<=t)
                {
                    cnt++;
                    //printf("%d %d %d %d %d\n", i, j, a, b, t);
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}