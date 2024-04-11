#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
string str;
int cnt[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) cnt[i]=0;
		cin>>str;
		if(k&1) 
		{
			for(int i=0;i<n;i++) str[i]='0'+'1'-str[i];
		}
		for(int i=0;i<n;i++)
		{
			if(str[i]=='0'&&k)
			{
				str[i]='1'; cnt[i]++;
				k--;
			}
		}
		if(k&1) {str[n-1]='0'+'1'-str[n-1]; cnt[n-1]++; k--;}
		cnt[0]+=k;
		cout<<str<<endl;
		for(int i=0;i<n;i++) printf("%d%c",cnt[i],i==n-1?'\n':' ');
	}
	return 0;
}