#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
	cin>>str;
	n=str.size();
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(str[i]=='Q'&&str[j]=='A'&&str[k]=='Q') cnt++;
	printf("%d\n",cnt);
	return 0;
}