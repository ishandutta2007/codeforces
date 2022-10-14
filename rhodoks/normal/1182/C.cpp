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

#define MAXN 201000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

string word[MAXN];
int cnt[MAXN];
int lst[MAXN];
int n;
int tem[1000];
const char upp[1000]={'a','e','i','o','u'};
bool f[1000];
int order[MAXN];
queue< pair <int,int> > q1,q2;
bool cmp(int i,int j)
{
	return cnt[i]<cnt[j] || cnt[i]==cnt[j] && lst[i]<lst[j];
}
bool flag[MAXN];
int main()
{
	f['a']=true;
	f['e']=true;
	f['i']=true;
	f['o']=true;
	f['u']=true;
	cin>>n;
	RPT(i,0,n)
	{
		cin>>word[i];
		lst[i]=-1;
		RPT(j,0,(word[i].size()))
			if (f[word[i][j]])
			{
				cnt[i]++;
				lst[i]=word[i][j];
			}
		//cout<<cnt[i]<<' '<<lst[i]<<endl;
	}
	RPT(i,0,n)
		order[i]=i;
	sort(order,order+n,cmp);
	//RPT(i,0,n)
	//	cout<<word[order[i]]<<endl;
	RPT(i,0,n-1)
	{
		if (!flag[i] && cnt[order[i]]==cnt[order[i+1]] && lst[order[i]]==lst[order[i+1]] && cnt[order[i]]>0)
		{
			flag[i]=flag[i+1]=true;
			q1.push(make_pair(order[i],order[i+1]));
		}
	}
	int last=-1;
	for (int i=0;i<n;i++)
	{
		if (!flag[i])
		{
			if (last==-1)
			{
				last=i;
			}
			else
			{
				if (cnt[order[last]]==cnt[order[i]])
				{
					q2.push(make_pair(order[last],order[i]));
					//cout<<'!'<<word[order[last]]<<' '<<word[order[i]]<<endl;
					last=-1;
				}
				else
					last=i;
			}
		}
	}
	pair <int,int> p1,p2;
	int ans;
	if (q2.size()>q1.size())
		cout<<(ans=q1.size())<<endl;
	else
		cout<<(ans=q2.size()+(q1.size()-q2.size())/2)<<endl;
	while (ans--)
	{
		if (q2.size()>0)
		{
			p1=q2.front();
			q2.pop();
		}
		else
		{
			p1=q1.front();
			q1.pop();
		}
		p2=q1.front();
		q1.pop();
		cout<<word[p1.first]<<' '<<word[p2.first]<<endl;
		cout<<word[p1.second]<<' '<<word[p2.second]<<endl;
	}
	return ~~(0^_^0);
}