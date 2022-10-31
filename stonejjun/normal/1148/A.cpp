#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int arr[101010];
int arr2[101010];
int dp[101010];
int pre[101010];
string st;

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    ll sum=0,cnt=0,chk=0,fl=0,hap=0,ans=0,lo=0,hi=0;

    scanf("%lld %lld %lld",&a,&b,&c);
    if(a==b)
    {
        printf("%lld",c*2+a+b);
        return 0;
    }
    else
    {
            printf("%lld",c*2+1+2*min(a,b));
    return 0;
    }
}