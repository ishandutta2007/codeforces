#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b,k;
string str;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	cin>>str;
	vector<int> ans;
	int cnt=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0') cnt++; else cnt=0;
		if(cnt==b) {cnt=0; ans.push_back(i);}
	}
	printf("%d\n",ans.size()-a+1);
	for(int i=0;i<ans.size()-a+1;i++)
		printf("%d ",ans[i]+1);
	return 0;
}