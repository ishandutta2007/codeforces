#include<bits/stdc++.h>
using namespace std;
int q;
long long n,x,tp,now;
int main()
{
	scanf("%lld%d",&n,&q);
	while(q--)
    {
        scanf("%lld",&x);
        tp=n,now=0;
        while(!(x&1))
        {
            now+=tp>>1;
            x>>=1;
            if(tp&1)x++;
            tp=tp+1>>1;
        }
        now+=x+1>>1;
        printf("%lld\n",now);
    }
}