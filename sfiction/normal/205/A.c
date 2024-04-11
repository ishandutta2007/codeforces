/*
ID: Sfiction
OJ: CF129 Div2
PROB: A
*/
#include <stdio.h>
int main()
{
    int i,N,dis,min,num,times;
    scanf("%d",&N);
    min=2000000000;
    for (i=0;i<N;i++)
    {
        scanf("%d",&dis);
        if (dis<min)
        {
            min=dis;
            num=i+1;
            times=1;
        }
        else if (dis==min) times=2;
    }
    if (times==2) printf("Still Rozdil");
    else printf("%d",num);
    return 0;
}