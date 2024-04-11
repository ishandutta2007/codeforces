#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k;
string str;
bool valid[26];
int main()
{
	scanf("%d%d",&n,&k);
	cin>>str;
	memset(valid,false,sizeof(valid));
	int most='a',least='z';
	for(int i=0;i<n;i++)
	{
		most=max(most,(int)str[i]);
		least=min(least,(int)str[i]);
		valid[str[i]-'a']=true;
	}
	if(n<k)
	{
		cout<<str;
		for(int i=n;i<k;i++)
			printf("%c",least);
		return 0;
	}
	int t=-1;
	for(int i=k-1;i>=0;i--)
		if(str[i]!=most) {t=i; break;}
	cout<<str.substr(0,t);
	for(int i=0;i<26;i++)
	{
		if(valid[i]&&i+'a'>str[t])
		{
			printf("%c",i+'a');
			break;
		}
	}
	for(int i=t+1;i<k;i++)
		printf("%c",least);
	return 0;
}