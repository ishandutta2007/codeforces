#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
bool used[26];
int main()
{
	cin>>str;
	scanf("%d",&k);
	int n=str.size();
	memset(used,false,sizeof(used));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(!used[str[i]-'a']) cnt++;
		used[str[i]-'a']=true;
	}
	int needed=max(0,k-cnt);
	if(k>n) puts("impossible"); else printf("%d\n",needed);
	return 0;
}