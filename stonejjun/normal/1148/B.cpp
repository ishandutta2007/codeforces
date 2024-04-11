#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll arr[201010];
ll arr2[201010];
int dp[101010];
int pre[101010];
string st;

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    ll sum=0,cnt=0,chk=0,fl=0,hap=0,ans=0,maxi=0;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&a,&b,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&o);
        arr[i]=o+a;
    }
    for(i=0;i<m;i++)
        scanf("%d",&arr2[i]);
    if(k>=min(n,m))
    {
        printf("-1");
        return 0;
    }
    for(i=0;i<=k;i++)
    {
        j=0;
        ll mm=m;
        while(j<mm)
        {
            ll mid=(j+mm)/2;
            if(arr2[mid]>=arr[i]) mm=mid;
            else j=mid+1;
        }
        //printf("%lld %lld %lld %lld\n",i,arr[i],j,arr2[j]);
        if(j+k-i>=m)
        {
            printf("-1");
            return 0;
        }
        maxi=max(maxi,arr2[j+k-i]+b);
    }
    printf("%lld",maxi);
}