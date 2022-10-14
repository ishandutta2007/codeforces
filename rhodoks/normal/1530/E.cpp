#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

void init()
{
	
}
char s[MAXN];
int cnt[MAXN]; 
int n;
void work()
{
	for (char c='a';c<='z';c++)
		cnt[c]=0;
	cin>>s;
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		cnt[s[i]]++;
	}
	int valnum=0;
	for (char c='a';c<='z';c++)
		valnum+=(bool)cnt[c];
	if (valnum==1)
	{
		cout<<s<<endl;
		return ;
	}
	queue<int> qa;
	queue<int> qb;
	char ca;
	for (char c='a';c<='z';c++)
	{
		if (cnt[c]==1)
		{
			cout<<c;
			for (char C='a';C<='z';C++)
				while (C!=c && cnt[C]--)
					putchar(C);
			cout<<endl;
			return ;
		}
	}
	for (char c='a';c<='z';c++)
	{
		if (cnt[c] && qa.size()==0)
		{
			while (cnt[c]--)
				qa.push(c);
			ca=c;
		}
		else if (cnt[c])
		{
			while (cnt[c]--)
				qb.push(c);
		}
	}
	if (qa.size()<=qb.size()+2)
	{
		putchar(qa.front());
		qa.pop();
		putchar(qa.front());
		qa.pop();
		while (qb.size())
		{
			putchar(qb.front());
			qb.pop();
			if (qa.size())
			{
				putchar(qa.front());
				qa.pop();
			}
		}
		cout<<endl;
		return;
	}
	if (valnum==2)
	{
		putchar(qa.front());
		qa.pop();
		while (qb.size())
		{
			putchar(qb.front());
			qb.pop();
		}
		while (qa.size())
		{
			putchar(qa.front());
			qa.pop();
		}
		cout<<endl;
		return;
	}
	MRK();
	ca=qa.front();
	putchar(qa.front());
	qa.pop();
	char cb=qb.front();
	putchar(qb.front());
	qb.pop();
	while (qa.size())
	{
		putchar(qa.front());
		qa.pop();
	}
	char cc;
	for (int i=0;i<n;i++)
	{
		cnt[s[i]]++;
	}
	for (char c='a';c<='z';c++)
		if (cnt[c] && c!=ca && c!=cb)
		{
			cc=c;
			putchar(cc); 
			break;
		}
	while (qb.size())
	{
		char ct=qb.front();
		//WRT(ct);
		if (ct!=cc)
		{
			putchar(ct);
		}
		else
			cc=-1;
		qb.pop();
	}
	cout<<endl;
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}