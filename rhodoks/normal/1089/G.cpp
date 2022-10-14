/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 500016, MOD = 1000000007;

int a[7][7];
int k;
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int t;
	t=read();
	while (t--)
	{
		ll ans=0x3f3f3f3f3f3f3f3f;
		k=read();
		int sum=0;
		for (int i=0;i<7;i++)
		{
			a[i][0]=read();
			sum+=a[i][0];
		}

		for (int i=0;i<6;i++)
			for (int j=0;j<7;j++)
				a[(j+1)%7][i+1]=a[j][i];
			/*
		for (int i=0;i<7;i++)
			{
				for (int j=0;j<7;j++)
					cout<<a[j][i]<<' ';
				cout<<endl;
			}
*/
		for (int i=0;i<7;i++)
		{
			//cout<<sum<<endl;
			int tmp=(k-1)/sum;
			int tsum=sum;
			int tk;
			tk=k-tmp*sum;
			tmp*=7;
			for (int j=0;j<7;j++)
			{

				if (tk)
				{
					tmp++;
					if (a[j][i])
						tk--;
				}
				if (!k)
					break;
			}
			ans=min(ans,(ll)tmp);
		}
		printf("%lld\n",ans);

	}
    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}