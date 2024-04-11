#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,q;
int cal(int x)
{
    if(x==1||x==2||x==3) return -1;

}
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&n);
        int cnt=0;
        if(n==1||n==2||n==3) {printf("-1\n"); continue;}
        if(n%2==1)
        {
            if(n<9)
            {
                printf("-1\n"); continue;
            }
            n-=9;
            cnt+=1;
        }
        if(n==2)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",cnt+(n/4));
    }
    return 0;
}