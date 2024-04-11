#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,a[MAXN];
string str;
map<char,int> cnt;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str; cnt.clear();
		bool f=true;
		for(int i=0;i<(int)str.size();i++)
		{
			if(str[i]>='a'&&str[i]<='z') cnt[str[i]]++;
			else if(!cnt[str[i]-'A'+'a']) f=false;
			else cnt[str[i]-'A'+'a']--;
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}