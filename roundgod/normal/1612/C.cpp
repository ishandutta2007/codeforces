#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k;
ll x;
ll find_num(int x)
{
    return 1LL*x*(x+1)/2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&k,&x);
        if(1LL*k*k<=x) {printf("%d\n",2*k-1); continue;}
        else if(find_num(k)<=x)
        {
            ll need=x-find_num(k);
            int l=0,r=k;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(find_num(k-1)-find_num(mid)<need) r=mid; else l=mid;  
            }
            printf("%d\n",k+(k-1-r)+1);
        }
        else
        {   
            int l=0,r=k;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(find_num(mid)<x) l=mid; else r=mid;  
            }
            printf("%d\n",l+1);
        }
    }
    return 0;
}