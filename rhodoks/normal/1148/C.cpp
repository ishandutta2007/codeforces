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

#define MAXN 610000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int p[MAXN];
int pos[MAXN];
queue<int> q1,q2;
int main()
{
	cin>>n;
	RPT(i,1,n+1)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	LL cnt=0;
	RPT(i,1,n+1)
	{
		if (pos[i]==i)
			continue;
		if (abs(i-pos[i])>=n/2)
		{
			cnt++;
			q1.push(pos[i]);
			q2.push(i);
		}
		else
		{
			LL n1=(pos[i]>n/2 ? 1:n);
			LL n2=(i>n/2 ? 1:n);
			cnt+=2;
			q1.push(pos[i]);
			q2.push(n1);
			q1.push(i);
			q2.push(n2);
			if (n1==n2)
			{
				q1.push(pos[i]);
				q2.push(n1);
				cnt++;
			}
			else
			{
				cnt+=3;
				q1.push(n1);
				q2.push(n2);
				q1.push(pos[i]);
				q2.push(n1);
				q1.push(i);
				q2.push(n2);
			}
		}
			pos[p[i]]=pos[i];
			pos[i]=i;
			swap(p[i],p[pos[p[i]]]);
	}
	cout<<cnt<<endl;
	RPT(i,0,cnt)
	{
		cout<<q1.front()<<' '<<q2.front()<<endl;
		q1.pop();
		q2.pop();
	}
	return ~~(0^_^0);
}