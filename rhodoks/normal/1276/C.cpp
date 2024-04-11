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

typedef pair<int,int> pii;

int n;
int a[MAXN];
pii p[MAXN];
int sum[MAXN];
int m[MAXN];


int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int cnt=0;
	p[cnt]={1,a[0]};
	for (int i=1;i<n;i++)
		if (a[i]==a[i-1])
			p[cnt].first++;
		else
			p[++cnt]={1,a[i]};
	cnt++;
	sort(p,p+cnt);
	for (int i=0;i<cnt;i++)
	{
		//cout<<p[i].first<<' '<<p[i].second<<endl;
		sum[i]+=p[i].first;
	}
	for (int i=1;i<cnt;i++)
		sum[i]+=sum[i-1];
	int ptr=0;
	int ans=0;
	int ansp,ansq;
	//WRT(cnt);
	for (int x=1;;x++)
	{
		while (p[ptr].first<=x && ptr<cnt)
			ptr++;
		int tmp;
		if (ptr==0)
			tmp=x*cnt;
		else
			tmp=sum[ptr-1]+x*(cnt-ptr);
		tmp=tmp/x*x;
		if (x>tmp/x)
			break;
		if (ans<tmp)
		{
			ansp=x;
			ansq=tmp/x;
			ans=tmp;
		}
		//WRT(ans);
	}
	cout<<ans<<endl<<ansp<<' '<<ansq<<endl;
	int t=ans;
	queue<int> q;
	for (int i=cnt-1;i>=0;i--)
	{
		if (p[i].first>ansp)
			p[i].first=ansp;
		while (p[i].first--)
		{
			q.push(p[i].second);
			t--;
			if (!t)
				break;
		}
		if (!t)
			break;
	}
	//WRT(1);
	int px=0,py=0;
	while (1)
	{
		int pos=q.front();
		//cout<<px<<' '<<py<<' '<<pos<<endl;
		q.pop();
		m[px*ansq+py]=pos;
		px++;
		py++;
		if (q.empty())
			break;
		if (px==ansp)
			px=0;
		if (py==ansq)
			py=0;
		while (m[px*ansq+py])
		{
			px++;
			if (px==ansp)
				px=0;
		}
	}
	for (int i=0;i<ans;i++)
	{
		printf("%d ",m[i]);
		if ((i+1)%ansq==0)
			putchar('\n');
	}
	return ~~(0^_^0);
}