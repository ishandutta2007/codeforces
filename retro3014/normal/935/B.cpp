#include <stdio.h>

int N;
char c;
int x=0;
int y=0;

bool b=0;

int main()
{
    int cnt=0;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++)
    {
        scanf("%c", &c);
        if(c=='U')
        {
            y++;
        }
        else
        {
            x++;
        }
        if(x>y)
        {
            if(!b && i!=0)
            {
                cnt++;
            }
            b=true;
        }
        else if(x<y)
        {
            if(b)
            {
                cnt++;
            }
            b=false;
        }
    }
    printf("%d", cnt);
    return 0;
}