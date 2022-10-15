#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char mp[MAXN][MAXN];
set<int> s1,s2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	bool f=true;
	for(int i=0;i<n;i++)
	{
		vector<int> st;
		st.clear();
		for(int j=0;j<m;j++)
			if(mp[i][j]=='#') st.push_back(j);
		for(int k=0;k<n;k++)
			for(int j=1;j<st.size();j++)
				if(mp[k][st[j]]!=mp[k][st[j-1]]) f=false;
	}
	if(f) puts("Yes"); else puts("No");
	return 0;
}