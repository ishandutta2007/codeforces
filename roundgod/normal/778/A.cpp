#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
string str1,str2;
bool valid[MAXN];
bool C(int x)
{
	string str="";
	memset(valid,true,sizeof(valid));
	for(int i=0;i<x;i++)
		valid[a[i]-1]=false;
	for(int i=0;i<n;i++)
		if(valid[i]) str+=str1[i];
	int now=0;
	for(int i=0;i<str.size();i++)
		if(str[i]==str2[now])
		{
			now++;
			if(now==str2.size()) break;
		}
	return now==str2.size();
}
int main()
{
	cin>>str1;
	cin>>str2;
	n=str1.size();
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) l=mid; else r=mid;
	}
	printf("%d\n",l);
	return 0;
}