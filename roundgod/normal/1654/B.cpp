#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
int cnt[26];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		int n=(int)str.size();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) cnt[str[i]-'a']++;
		int id=0;
		while(id<n)
		{
			if(cnt[str[id]-'a']==1) break;
			cnt[str[id]-'a']--;
			id++;
		}
		cout<<str.substr(id,n-id)<<endl;
	}
	return 0;
}