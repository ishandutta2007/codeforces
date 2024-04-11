#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 810000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m;
int l[MAXN],r[MAXN];
int tmp[MAXN];
int diff[MAXN];
int ord[MAXN];
vector<int> bg,ed;

bool cmp(int x,int y)
{
	return l[x]<l[y];
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		bg.clear();
		ed.clear();
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			ord[i]=i;
			scanf("%d%d",&l[i],&r[i]);
			l[i]=2*l[i];
			r[i]=2*r[i]+1;
			//r[i]--;
			tmp[2*i-2]=l[i];
			tmp[2*i-1]=r[i];
		}
		int sum=0;
		sort(ord+1,ord+1+n,cmp);
		int ll=-0x7f3f3f3f;
		int rr=ll;
		for (int i=1;i<=n;i++)
			if (l[ord[i]]>rr)
			{
				sum++;
				ll=l[ord[i]];
				rr=r[ord[i]];
			}
			else
			{
				rr=max(rr,r[ord[i]]);
			}
		//WRT(sum);
		sort(tmp,tmp+2*n);
		m=unique(tmp,tmp+2*n)-tmp;
		for (int i=0;i<=2*n+2;i++)
			diff[i]=0;
		for (int i=1;i<=n;i++)
		{
			l[i]=lower_bound(tmp,tmp+m,l[i])-tmp+1;
			diff[l[i]]++;
			r[i]=lower_bound(tmp,tmp+m,r[i])-tmp+1;
			diff[r[i]]--;
			//cout<<l[i]<<' '<<r[i]<<endl;
		}
		for (int i=1;i<=m;i++)
		{
			diff[i]+=diff[i-1];
			//cout<<i<<' '<<diff[i]<<endl;
		}
		for (int i=1;i<=2*n;i++)
			if (diff[i]==1 && diff[i-1]>1 && diff[i+1]>1)
				bg.push_back(i);
				/*
		MRK();
		for (auto p:bg)
			cout<<p<<' ';
		cout<<endl;
		*/
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int posl=lower_bound(bg.begin(),bg.end(),l[i])-bg.end();
			int posr=lower_bound(bg.begin(),bg.end(),r[i])-bg.end();
			ans=max(ans,posr-posl);
		}
		if (sum+ans!=n)
			cout<<sum+ans<<endl;
		else
			cout<<n-1<<endl;
	}
	return ~~(0^_^0);
}