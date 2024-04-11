#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int t[MAXN],f[MAXN];

int a[MAXN] ,b[MAXN];//b
long long cnt;
void merge_sort(int l , int r)
{
    if(r-l > 0)//1
    {
        int mid = (l+r) / 2 ;
        int i = l; //
        int p = l , q = mid+1;
        merge_sort(l , mid);
        merge_sort(mid+1 , r);
        //printf("%d-%d  %d-%d\n",p,mid ,q ,r);
        while(p<=mid || q<=r)//
        {
            if(q>r || (p<=mid && a[p]<=a[q]))//
                b[i++] = a[p++];
            else
            {
                b[i++] = a[q++];
                cnt += mid -p +1;//
            }
        }
        for(i = l ; i <= r; i++)//ba
            a[i] = b[i];
    }
}
LL getans()
{
	cnt=0;
        for(int i = 1 ; i <= n; i ++)
            a[i]=t[i];
        cnt = 0;
        merge_sort(1 , n);
    return cnt;
}
int main()
{
	scanf("%d",&n);
	//cin>>n;
	//n=300000;
	LL ans1,ans2;
	int ans=0;
	bool lst=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		//f[i]=rand();
	}
	for (int i=29;i>=0;i--)
	{
		for (int j=1;j<=n;j++)
		{
			t[j]=(((f[j]^(1<<i))>>i)<<i);
		}
		ans1=getans();
		//cout<<endl<<ans1<<endl;
		for (int j=1;j<=n;j++)
		{
			t[j]=(((f[j]^0)>>i)<<i);
		}
		ans2=getans();
		//WRT(ans2);
		if (ans1<ans2)
		{
			ans^=(1<<i);
			for (int j=1;j<=n;j++)
				f[j]^=(1<<i);
		}
		//cout<<ans1<<' '<<ans2<<endl;
	}
	//for (int i=1;i<=n;i++)
	//	cout<<f[i]<<' ';
	//cout<<endl;
	printf("%lld %d",min(ans1,ans2),ans);
	return ~~(0^_^0);
}