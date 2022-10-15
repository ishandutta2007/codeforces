#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
map<string,int> mp;
bool used[26];
int main()
{
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		memset(used,false,sizeof(used));
		cin>>str;
		for(int j=0;j<str.size();j++)
			used[str[j]-'a']=true;
		string S="";
		for(int j=0;j<26;j++)
			if(used[j]) S=S+(char)('a'+j);
		if(mp.find(S)==mp.end())
		{
			cnt=cnt+1;
			mp[S]=1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}