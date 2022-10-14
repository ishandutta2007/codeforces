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

#define MAXN 1010
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

string s[1010][1010]; 
string t;
int n,k;
vector<int> g[MAXN];
int h[200][200];
int in[MAXN];
void add(int x,int y)
{
	if (h[x][y])
		return;
	h[x][y]=1;
	g[x].push_back(y);
	in[y]++;
}
string ans;
int cnt[MAXN];
void work()
{
	cin>>n>>k;
	int p;
	for (int i=0;i<n;i++)
	{
		cin>>p;
		for (int i=0;i<k;i++)
		{
			cin>>s[p][i];
			for (auto q:s[p][i])
				cnt[q]++;
		}
	}
	string *lst=NULL,*pos;
	for (int i=0;i<n;i++)
		for (int j=0;j<k;j++) 
		{
			pos=&s[i][j];
			if (lst)
			{
				for (int p=0;p<min((*pos).size(),(*lst).size());p++)
				{
					if ((*pos)[p]!=(*lst)[p])
					{
						h[(*lst)[p]][(*pos)[p]]=1;
						//add(lst[p],pos[p]);
						//cout<<pos<<endl<<lst<<endl<<lst[p]<<' '<<pos[p]<<endl;
						break;
							
					}
					if (p==min((*pos).size(),(*lst).size())-1 && (*lst).size()>(*pos).size())
					{
						cout<<"IMPOSSIBLE"<<endl;
						return;
					}
				}
			}
			lst=&s[i][j];
		}
	for (int i='a';i<='z';i++)
		for (int j='a';j<='z';j++)
			if (h[i][j])
			{
				g[i].push_back(j);
				in[j]++;
			}
	queue<char> q;
	for (int i='a';i<='z';i++)
		if (in[i]==0 && cnt[i])
			q.push(i);
	while (!q.empty())
	{
		char pos=q.front();
		q.pop();
		ans.push_back(pos);
		for (auto p:g[pos])
		{
			if ((--in[p])==0)
				q.push(p);
		}
	}
	for (int i='a';i<='z';i++)
		if (in[i])
		{
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}