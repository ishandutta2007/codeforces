#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
vector<int> a[MAXN],b[MAXN];
int main()
{
	cin>>str;
	int n=str.size(),cnt=0;
	for(int i=0;i<n;i++)
		if(str[i]=='0') cnt++; else cnt--;
	if(cnt<=0)
	{
		puts("-1");
		return 0;
	}
	int t1=0,t2=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0') {a[t1].push_back(i+1); t1=(t1+1)%cnt;}
		else {b[t2].push_back(i+1); t2=(t2+1)%cnt;}
	}
	bool f=true;
	for(int i=0;i<cnt;i++)
		if(a[i].size()!=b[i].size()+1) {f=false; break;}
	if(!f)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<cnt;i++)
		for(int j=0;j<b[i].size();j++)
			if(b[i][j]<a[i][j]||b[i][j]>a[i][j+1]) {f=false; break;}
	if(!f)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d ",a[i].size()+b[i].size());
		for(int j=0;j<b[i].size();j++)
			printf("%d %d ",a[i][j],b[i][j]);
		printf("%d\n",a[i].back());
	}
	return 0;
}