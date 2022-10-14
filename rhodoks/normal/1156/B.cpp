#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int T;
char str[1000];
int cnt[1000];
int len;
int num;
char f[MAXN];

int main()
{
	cin>>T;
	getchar();
	while (T--)
	{
		MST(cnt,0);
		cin>>str;
		//cout<<endl;
		//WRT(str);
		len=strlen(str);
		RPT(i,0,len)
		{
			if (cnt[str[i]]==0)
				num++;
			cnt[str[i]]++;
		}
		int tem=0;
		RPT(i,0,26)
			if (cnt[i+'a'])
				f[tem++]=(char)(i+'a');
		//WRT(tem);
		if (tem>=4)
		{
			for (int i=1;i<tem;i+=2)
				while (cnt[f[i]]--)
					cout<<f[i];
			for (int i=0;i<tem;i+=2)
				while (cnt[f[i]]--)
					cout<<f[i];
		}
		if (tem==1)
			cout<<str;
		if (tem==2)
		{
			if (f[1]-f[0]==1)
				cout<<"No answer";
			else
			{
				cout<<str;
			}
		}
		if (tem==3)
		{
			if (f[1]-f[0]==1 && f[2]-f[1]==1)
				cout<<"No answer";
			else if (f[1]-f[0]==1 && f[2]-f[1]!=1)
			{
				while (cnt[f[0]]--)
					cout<<f[0];
				while (cnt[f[2]]--)
					cout<<f[2];
				while (cnt[f[1]]--)
					cout<<f[1];
			}
			else if (f[1]-f[0]!=1 && f[2]-f[1]==1)
			{
				while (cnt[f[2]]--)
					cout<<f[2];
				while (cnt[f[0]]--)
					cout<<f[0];
				while (cnt[f[1]]--)
					cout<<f[1];
			}
			else
				cout<<str;
		}
		cout<<endl;
	}
	return ~~(0^_^0);
}