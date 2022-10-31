#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
typedef pair<int,int> pii;
vector<int> v;
int arr[5501010];
char cc[101010];
int dp[101010];

int main()
{
    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; //
    int ans=0,hap=0,dap=0,cnt=0,chk=0;
    scanf("%lld",&n);
    while(n--)
    {
        long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; //
        int ans=0,hap=0,dap=0,cnt=0,chk=0;
        scanf("%lld",&t);
        z=t;
        t++;
        while(t!=1)
        {
            if(t%2==1) chk=1;
            t/=2;
            cnt++;
        }
        if(chk==1)
        {
            cnt++;
            printf("%lld\n",(long long int)((1<<cnt)-1));
        }
        else
        {
            q=sqrt(z);
            for(i=2;i<=q;i++)
            {
                if(z%i==0)
                {
                    printf("%lld\n",z/i);
                    break;
                }
            }
            if(i==q+1)
                printf("1\n");
        }
    }


}