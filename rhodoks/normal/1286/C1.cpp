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

string s;
multiset<string> st;
string ss[110];

char ans[1000];
bool cmp(string s1,string s2)
{
	return s1.size()<s2.size();
}
int buc[1100];
int main()
{
	int n;
	cin>>n;
	if (n==1)
	{
		cout<<"? "<<1<<' '<<1<<'\n';
		fflush(stdout);
		char c;
		cin>>c;
		cout<<"! "<<c;
		fflush(stdout);
		return 0;
	}
	cout<<"? "<<1<<' '<<n<<'\n';
	fflush(stdout);
	for (int i=0;i<n*(n+1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.insert(s);	
	} 
	cout<<"? "<<2<<' '<<n<<'\n';
	fflush(stdout);
	for (int i=0;i<n*(n-1)/2;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		st.erase(st.find(s));	
	} 
	int cnt=0;
	for (auto p:st)
	{
		ss[cnt++]=p;
	}
	sort(ss,ss+cnt,cmp);
	ans[0]=ss[0][0];
	
	for (int i=1;i<cnt;i++)
	{
		for (auto p:ss[i-1])
			buc[p]--;
		for (auto p:ss[i])
			buc[p]++;
		for (int j=0;j<255;j++)
			if (buc[j]>0)
			{
				buc[j]=0;
				ans[i]=j;
			}
	}
	cout<<"! "<<ans;
	
		fflush(stdout);
	return ~~(0^_^0);
}