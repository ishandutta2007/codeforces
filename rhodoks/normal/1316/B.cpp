#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 5100
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN];
string re[MAXN];
int ord[MAXN];
int len;
bool cmp(int x,int y)
{
	if (re[x]<re[y])
		return true;
	if (re[x]>re[y])
		return false;
	return x<y;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>len>>s;
		for (int i=1;i<=len;i++)
		{
			ord[i]=i;
			re[i].clear();
			re[i].resize(len);
		}
		for (int i=1;i<=len;i++)
		{
			for (int j=i-1;j<len;j++)
				re[i][j-(i-1)]=s[j];
			if ((len-i) & 1)
				for (int j=0;j<i-1;j++)
					re[i][j+len-(i-1)]=s[j];
			else
				for (int j=0;j<i-1;j++)
					re[i][j+len-(i-1)]=s[i-2-j];
			//cout<<i<<' '<<re[i]<<endl;
		}
		int ans=1;
		for (int i=2;i<=len;i++)
			if (re[i]<re[ans])
				ans=i;
		cout<<re[ans]<<endl<<ans<<endl;
	}
	return ~~(0^_^0);
}