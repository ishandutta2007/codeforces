#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int T,n,m,k;
struct rec
{
	int val,cnt;
	long long sum;
	rec(int x,int y,long long z){val=x,cnt=y,sum=z;}
};
vector<rec> a,b;
int w[111111];
//mt19937 rng(58);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--)
	{
		a.clear();b.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			//w[i]=rng()%100000+1;
			cin>>w[i];
		}
		long long ans=0;
		for(int i=n;i>=1;i--)
		{
			{vector<rec> tmp;b.swap(tmp);}
			//insert {w[i],1,0}
			rec cur{w[i],1,0};
			for(auto z:a)
			{
				int t=z.val;
				int sep=(w[i]+t-1)/t;
				int lower=w[i]/sep;
				if(lower!=cur.val)
				{
					b.push_back(cur);
					cur=rec(lower,z.cnt,z.sum+1ll*z.cnt*(sep-1));
				}
				else
				{
					cur.cnt+=z.cnt;
					cur.sum+=z.sum+1ll*z.cnt*(sep-1);
				}
			}
			b.push_back(cur);
//			cerr<<"round "<<n-i+1<<endl;
			for(auto z:b)
			{
//				cerr<<z.val<<' '<<z.cnt<<' '<<z.sum<<endl;
				ans+=z.sum%MOD;
			}
			a.swap(b);
		}
		cout<<ans%MOD<<endl;
	}
	return 0;
}