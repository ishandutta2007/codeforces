#include <stdio.h>

int T, N;
int s, e, mid;
bool solved;
struct S{
    int ax, ay;
};
S ans;

long long calc(long long x, long long y)
{
    return (x*x)-(x/y)*(x/y);
}
int main()
{
    scanf("%d", &T);
    while(T>0)
    {
        T--;
        scanf("%d", &N);
        solved=false;
        for(int i=1; (long long)(i/2)*(long long)(i/2)<=(long long)N; i++)
        {
            s=1;
            e=i;
            while(s<=e)
            {
                mid=(s+e)/2;
                if(calc(i, mid)==N)
                {
                    ans.ax=i;
                    ans.ay=mid;
                    solved=true;
                    break;
                }
                else if(calc(i, mid)>N)
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            if(solved)
            {
                break;
            }
        }
        if(solved)
        {
            printf("%d %d\n", ans.ax, ans.ay);
        }
        else
        {
            printf("-1\n");
        }
    }
}