#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
typedef pair<int,int> pii;
vector<int> v;
int arr[101010];
char cc[101010];
int dp[101010];

int main()
{
    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; //
    long long ans=0,hap=0,dap=0,cnt=0;
    scanf("%lld %lld",&a,&n);
    for(i=n;i>=1;i--)
    {
        scanf("%lld",&c);
        if(c%2==1)
        {
            arr[i]=1;
            cnt++;
        }
    }
    if(a%2==0)
    {
        if(arr[1]==1) printf("odd");
        else printf("even");
        return 0;
    }
    if(cnt%2==1)
        printf("odd");
    else printf("even");





    return 0;
}