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

#define MAXN 410000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int sa[MAXN],ea[MAXN],sb[MAXN],eb[MAXN];
int tmp[MAXN<<2];
int m;
int ord[2][MAXN];

bool cmp1(int x,int y)
{
	return sa[x]<sa[y];
}

bool cmp2(int x,int y)
{
	return ea[x]<ea[y];
}

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&sa[i],&ea[i],&sb[i],&eb[i]);
		tmp[4*i]=sa[i];
		tmp[4*i+1]=ea[i];
		tmp[4*i+2]=sb[i];
		tmp[4*i+3]=eb[i];
	}
	sort(tmp,tmp+4*n);
	m=unique(tmp,tmp+4*n)-tmp;
	for (int i=0;i<n;i++)
	{
		sa[i]=lower_bound(tmp,tmp+m,sa[i])-tmp+1;
		sb[i]=lower_bound(tmp,tmp+m,sb[i])-tmp+1;
		ea[i]=lower_bound(tmp,tmp+m,ea[i])-tmp+1;
		eb[i]=lower_bound(tmp,tmp+m,eb[i])-tmp+1;
		//cout<<sa[i]<<' '<<ea[i]<<' '<<sb[i]<<' '<<eb[i]<<endl;
	}
	for (int i=0;i<n;i++)
		ord[0][i]=ord[1][i]=i;
	sort(ord[0],ord[0]+n,cmp1);
	sort(ord[1],ord[1]+n,cmp2);
	set<int> st1;
	set<int> st2;
	int ptr=0;
	for (int i=0;i<n;i++)
	{
		int pos=ord[0][i];
		while (ea[ord[1][ptr]]<sa[pos] && ptr<n)
		{
			st1.insert(sb[ord[1][ptr]]);
			st1.insert(eb[ord[1][ptr]]);
			ptr++;
		}
		if (*st1.lower_bound(sb[pos])>=sb[pos] && *st1.lower_bound(sb[pos])<=eb[pos])
		{
			cout<<"NO";
			return 0;
		}
	}
	ptr=n-1;
	for (int i=n-1;i>=0;i--)
	{
		int pos=ord[1][i];
		while (sa[ord[0][ptr]]>ea[pos] && ptr>=0)
		{
			st2.insert(sb[ord[0][ptr]]);
			st2.insert(eb[ord[0][ptr]]);
			ptr--;
		}
		if (*st2.lower_bound(sb[pos])>=sb[pos] && *st2.lower_bound(sb[pos])<=eb[pos])
		{
			//cout<<eb[pos]
			cout<<"NO";
			return 0;
		}
	}
	st1.clear();
	st2.clear();
	for (int i=0;i<n;i++)
	{
		swap(sa[i],sb[i]);
		swap(ea[i],eb[i]);
	}
	for (int i=0;i<n;i++)
		ord[0][i]=ord[1][i]=i;
	sort(ord[0],ord[0]+n,cmp1);
	sort(ord[1],ord[1]+n,cmp2);
	ptr=0;
	for (int i=0;i<n;i++)
	{
		int pos=ord[0][i];
		while (ea[ord[1][ptr]]<sa[pos] && ptr<n)
		{
			st1.insert(sb[ord[1][ptr]]);
			st1.insert(eb[ord[1][ptr]]);
			ptr++;
		}
		if (*st1.lower_bound(sb[pos])>=sb[pos] && *st1.lower_bound(sb[pos])<=eb[pos])
		{
			cout<<"NO";
			return 0;
		}
	}
	ptr=n-1;
	for (int i=n-1;i>=0;i--)
	{
		//WRT(i);
		int pos=ord[1][i];
		while (sa[ord[0][ptr]]>ea[pos] && ptr>=0)
		{
			//cout<<*st2.lower_bound(eb[pos])<<' '<<sb[pos]<<' '<<eb[pos]<<endl;
			st2.insert(sb[ord[0][ptr]]);
			st2.insert(eb[ord[0][ptr]]);
			ptr--;
		}
		if (*st2.lower_bound(sb[pos])>=sb[pos] && *st2.lower_bound(sb[pos])<=eb[pos])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return ~~(0^_^0);
}