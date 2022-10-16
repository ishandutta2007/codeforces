#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,h,c,t;
void solve()
{
	if(t==h)
	{
		puts("1");
		return ;
	}
	if(t<=(h+c)>>1)
	{
		puts("2");
		return ;
	}
	if(t>(h+c)>>1)
	{
		int tmp;
        double pans=h-t;
        int l=1,r=5000000,temp;
        while (l<=r)
		{
        	int mid=(l+r)/2;
        	int i=1+mid*2;
        	tmp=h+(h+c)*mid;
        	if(tmp%i==0)
        		if(tmp/i==t)
				{
                	temp=mid;
                    break;
                }
            double fenzi=tmp;
            double fenmu=i;
            double ans=fenzi/fenmu;
            if(ans<t)
			{
                temp=mid;
                r=mid-1;
            }
			else
                l=mid+1;
        }
        int i=1+temp*2;
        tmp=h+(h+c)*temp;
        if(tmp%i==0&&tmp/i==t)
            cout<<i<<endl;
        else
		{
            int pi=i-2;
            int ptmp=tmp-h-c;
            double pans=(1.0*ptmp)/(1.0*pi)-t;
            double ans=t-(1.0*tmp)/(1.0*i);
            if(pans<=ans)
                cout<<i-2<<endl;
            else
                cout<<i<<endl;
		}
	}
}
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&h,&c,&t);
		solve();
	}
	return 0;
}