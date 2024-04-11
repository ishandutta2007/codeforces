#include<bits/stdc++.h>
using namespace std;

long long int arr[101010];
long long int arr2[101010];
long long int digit[10101];


long long int  pw (long long down, long long bitup) {
	long long int ans = 1,mod=998244353;

	while (bitup) {
		if (bitup % 2) ans = ans * down % mod;
		down = down * down % mod;
		bitup /= 2;
	}

	return ans;
}

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,ans=0;
    scanf("%lld",&n);
    digit[11]=n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    for(i=1;i<=n;i++)
    {
        k=0;
        while(arr[i])
        {
            a=arr[i]%10;
            k++;
            for(l=0;l<=11;l++)
            {
                if(digit[l]==0) continue;
                if(l>=k)
                {
                    long long p=2*(k-1);
                    ans+=a*digit[l]*pw(10,p)*11;
                    ans=ans%998244353;
                }
                else if(l<k)
                {
                    ans+=a*digit[l]*pw(10,k+l-1)*2;
                    ans=ans%998244353;
                }
               // printf("%lld %lld %lld %lld\n",i,k,l,ans);
            }
            arr[i]/=10;

        }
        digit[10]--;
        digit[k]++;
    }
    printf("%lld",ans);
}