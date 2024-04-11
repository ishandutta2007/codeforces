#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN];
vector<int> v;

int main()
{
	bool f=false;
	cin>>s;
	int len=strlen(s);
	int l=0,r=len-1;
	while (1)
	{
		while (s[l]!='(' && l<len)
			l++;
		while (s[r]!=')' && r>=0)
			r--;
		if (l<len && s[l]=='(' && r>=0 && s[r]==')' && l<r)
		{
			v.push_back(l);
			v.push_back(r);
			l++;
			r--;
			f=true;
		}
		else
			break;
	}
	sort(v.begin(),v.end());
	if (f==0)
	{
		cout<<0;
		return 0;
	}
	cout<<1<<endl;
	cout<<v.size()<<endl;
	for (auto p:v)
		cout<<p+1<<' ';
	return ~~(0^_^0);
}