#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		vector<int> v;
		scanf("%d",&n);
		bool one=false,zero=false;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&x);
			if(x==0) zero=true;
			if(x==1) one=true;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		if(zero&&one) {puts("NO"); continue;}
		if(!one) {puts("YES"); continue;}
		bool f=true;
		for(int i=0;i<(int)v.size()-1;i++) if(v[i+1]==v[i]+1) {f=false; break;}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}