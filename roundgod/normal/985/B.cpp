#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
int cnt[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin>>str[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]-'0') cnt[j]++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(str[i][j]-'0') cnt[j]--;
		bool f=true;
		for(int j=0;j<m;j++)
			if(cnt[j]<=0) {f=false; break;}
		if(f) {puts("YES"); return 0;}
		for(int j=0;j<m;j++)
			if(str[i][j]-'0') cnt[j]++;
	}
	puts("NO");
	return 0;
}