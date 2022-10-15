#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string S;
int cnt[27];
int main()
{
	cin>>S;
	int n=S.size();
	for(int i=0;i<n;i++)
	{
		if(S[i]>='a'&&S[i]<='z') cnt[S[i]-'a']++;
		else if(S[i]=='B') cnt[26]++;
	}
	int res=INF;
	res=min(res,cnt[0]/2);
	res=min(res,cnt[1]);
	res=min(res,cnt['s'-'a']);
	res=min(res,cnt['u'-'a']/2);
	res=min(res,cnt['l'-'a']);
	res=min(res,cnt['r'-'a']);
	res=min(res,cnt[26]);
	printf("%d\n",res);
	return 0;
}