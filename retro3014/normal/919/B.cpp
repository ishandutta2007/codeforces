#include <stdio.h>

int a[20];
int cnt;

int main()
{
    scanf("%d", &cnt);
    int k;
    int sum;
    while(1)
    {
        a[0]++;
        k=0;
        while(a[k]>=10)
        {
            a[k+1]+=a[k]/10;
            a[k]=a[k]%10;
            k++;
        }
        sum=0;
        for(int i=0; i<20; i++)
        {
            sum+=a[i];
        }
        if(sum==10)
        {
            cnt--;
            if(cnt==0)
            {
                int t=20-1;
                while(a[t]==0)
                {
                    t--;
                }
                for(int i=t; i>=0; i--)
                {
                    printf("%d", a[i]);
                }
                return 0;
            }
        }
    }
    return 0;
}