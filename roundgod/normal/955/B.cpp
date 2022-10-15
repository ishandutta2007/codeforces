#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int cnt[26];
vector<int> G;
int main()
{
	cin>>str;
	n=str.size();
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
		cnt[str[i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]) G.push_back(cnt[i]);
	sort(G.begin(),G.end());
	if(G.size()<2||G.size()>4||(G.size()==3&&G[G.size()-1]==1)||(G.size()==2&&G[0]==1))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}