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


#define GET(mask,n) ((mask>>n)&1)
#define SET0(mask,n) mask=(mask&(~(1<<n)));
#define SET1(mask,n) mask=(mask|(1<<n))
#define ALL(n) ((1<<n)-1)
#define SUB(i,mask) for (int i=mask;i;i=(i-1)&mask)
#define LOWBIT(x) (x&-x)


using namespace std;

int n,m,p;
char buf[100];
LL ans=0;
LL ansv=0;
LL a[MAXN];
LL input()
{
	LL tmp=0;
	scanf("%s",buf);
	for (int i=0;i<m;i++)
		tmp+=(1ll<<i)*(buf[i]-'0');
	return tmp;
}
 
void init()
{
	cin>>n>>m>>p;
	for (int i=0;i<n;i++)
		a[i]=input();
}

void work()
{
	int id=((rand()<<15)+rand())%n; 
	vector<LL> rec;
	for (int i=0;i<m;i++)
		if ((a[id]>>i)&1)
			rec.push_back((1ll<<i)); 
	WRT(id);
	//for (auto p:rec)
	//	WRT(p) 
	vector<int> buc;
	vector<int> sum;
	buc.resize((1<<rec.size()),0);
	sum.resize((1<<rec.size()),0);
	for (int i=0;i<n;i++)
	{
		int tmp=0;
		for (int j=0;j<rec.size();j++)
			if (a[i]&rec[j])
				SET1(tmp,j);
		//WRT(tmp)
		buc[tmp]++;
	}
	for (int i=ALL(rec.size());i;i--)
	{
		//cout<<i<<' '<<buc[i]<<endl;
		if (buc[i]+sum[i]>=(n+1)/2 && __builtin_popcount(i)>ansv)
		{
			ansv=__builtin_popcount(i);
			LL tmp=0;
			for (int j=0;j<rec.size();j++)
				if ((i>>j)&1)
					tmp+=rec[j];
			ans=tmp;
		}
		SUB(j,i)
			sum[j]+=buc[i];
	}
	//WRT(ans)
	WRT(ansv)
}

int main()
{
	srand(19491); 
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=10;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	for (int i=0;i<m;i++)
		putchar('0'+((ans>>i)&1));
	return ~~(0^_^0);
}