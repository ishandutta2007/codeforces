#include<bits/stdc++.h>
using namespace std;

char c[1010101];
int p[1010101];
int arr[1010101];
int arr2[1010101];
int dp[1010101];

int main()
{
    int a,b,i,j,k,l,m,n,cnt=0,hap=0,vcnt=0;
    scanf("%d",&n);
    for(i=n;i<=2*n;i++)
    {
        int chk=0;
        for(j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                chk=1;
                break;
            }
        }
        if(chk==0)
        {
            break;
        }
    }
    int fin=i;
    printf("%d\n",fin);
    for(i=1;i<n;i++)
    {
        printf("%d %d\n",i,i+1);
    }
    printf("1 %d\n",n);
    fin-=n;
    while(fin!=0)
    {
        fin--;
        hap++;
        printf("%d %d\n",hap,hap+n/2);
    }
}