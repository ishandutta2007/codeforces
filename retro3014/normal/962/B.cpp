#include <stdio.h>
#include <algorithm>

using namespace std;

int N, A, B;
char c;
int chk;
int PA, PB;

int a, b;

int main()
{
    scanf("%d%d%d", &N, &A, &B);
    PA=A;
    PB=B;
    getchar();
    for(int i=1; i<=N; i++)
    {
        scanf("%c", &c);
        if(c=='.')  chk++;
        else
        {
            if(chk!=0)
            {
                if(chk%2==0)
                {
                    a+=(chk/2);
                    b+=(chk/2);
                }
                else
                {
                    a+=(chk/2);
                    b+=(chk/2);
                    if(A>B)
                    {
                        A--;
                        a++;
                    }
                    else
                    {
                        B--;
                        b++;
                    }
                }
            }
            chk=0;
        }
    }
    if(chk!=0)
    {
        if(chk%2==0)
        {
            a+=(chk/2);
            b+=(chk/2);
            A-=a;
            B-=b;
        }
        else
        {
            a+=(chk/2);
            b+=(chk/2);
            (A>B)?a++:b++;
            A-=a;
            B-=b;
        }
    }
    printf("%d", min(a, PA)+min(b, PB));
    return 0;
}