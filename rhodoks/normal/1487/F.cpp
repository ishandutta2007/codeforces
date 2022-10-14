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

struct Integer
{
public:
	vector<int> v;
	
	Integer()
	{
		
	}
	
	Integer(int n)
	{
		while (n--)
			v.push_back(1);
	}
	
	void input()
	{
		string s;
		cin>>s;
		for (auto p:s)
			v.push_back(p-'0');
		reverse(v.begin(),v.end());
	}
	
	void output()
	{
		for (int i=v.size()-1;i>=0;i--)
			cout<<v[i];
	}
	
	int& operator[](int x)
	{
		return v[x];
	} 
	
	int length()
	{
		return v.size();
	}
	
};

bool operator<(Integer x1,Integer x2)
{
	if (x1.length()!=x2.length())
		return x1.length()<x2.length();
	for (int i=x1.length()-1;i>=0;i--)
		if (x1[i]!=x2[i])
			return x1[i]<x2[i];
	return false;
}


bool operator==(Integer x1,Integer x2)
{
	if (x1<x2 || x2<x1)
		return false;
	return true;
}


Integer operator-(Integer x1,Integer x2)
{
	if (x2<x1)
		swap(x1,x2);
	for (int i=0;i<x1.length();i++)
	{
		x2[i]-=x1[i];
		if (x2[i]<0)
		{
			x2[i]+=10;
			x2[i+1]--;
		}
	}
	for (int i=x2.length()-1;i>=1;i--)
		if (x2[i]==0)
			x2.v.resize(i);
		else
			break;
	return x2;
}

map<Integer,int> dp[100];
void init()
{

}

void upd(int id,Integer x,int n)
{
	if (dp[id].find(x)==dp[id].end())
		dp[id][x]=n;
	else
		dp[id][x]=min(dp[id][x],n);
}

void work()
{
	Integer x;
	x.input();
	dp[x.length()+1][x]=0;
	for (int i=x.length()+1;i>=1;i--)
	{
		//WRT(i);
		for (auto p:dp[i])
		{
			Integer tmp=p.first;
			int cnt=p.second;
			//tmp.output();
			//cout<<' '<<cnt<<endl;
			while (!(tmp<Integer(i)))
			{
				tmp=tmp-Integer(i);
				cnt+=i;
			}
			upd(i-1,tmp,cnt);
			tmp=tmp-Integer(i);
			cnt+=i;
			upd(i-1,tmp,cnt);
		}
	}
	x=Integer(1)-Integer(1);
	cout<<dp[0][x]<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}