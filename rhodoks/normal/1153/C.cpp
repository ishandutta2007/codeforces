#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 1000000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[1000000];
int len;
int l,r,w;
bool judge()
{
	
}

int main()
{
	cin>>len;
	getchar();
	fgets(s,900000,stdin);
	if (len%2==1)
	{
		cout<<":(";
		return 0;
	}
	RPT(i,0,len)
	{
		if (s[i]=='(')
			l++;
		if (s[i]==')')
			r++;
		if (s[i]=='?')
			w++;
	}
	int numl=len/2-l;
	int numr=len/2-r;
	if (numl<0 || numr <0)
	{
		cout<<":(";
		return 0;
	}
	char st[1000000];
	strcpy(st,s);
	//cout<<st;
	int cnt=0;
	int tem=0;
	bool ff=true;
	RPT(i,0,len)
	{
		if (st[i]=='?')
		{
			if (++cnt<=numl)
				st[i]='(';
			else
				st[i]=')';
		}
		if (st[i]=='(')
			tem++;
		else
			tem--;
		//WRT(tem);
		if (tem<=0 && len!=i+1)
		{
			ff=false;
			break;
		}
	}
	if (ff)
	{
		cout<<st;
		return 0;
	}
	strcpy(st,s);
	cnt=0;
	tem=0;
	ff=true;
	RPT(i,0,len)
	{
		if (st[i]=='?')
		{
			if (++cnt<=numr)
				st[i]=')';
			else
				st[i]='(';
		}
		if (st[i]=='(')
			tem++;
		else
			tem--;
		if (tem<=0 && len!=i+1)
		{
			ff=false;
			break;
		}
	}
	if (ff)
	{
		cout<<st;
		return 0;
	}
	cout<<":(";

	return ~~(0^_^0);
}