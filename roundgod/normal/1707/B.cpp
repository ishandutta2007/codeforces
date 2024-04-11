#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 21
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
vector<ll> v;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		v.clear();
		for(int i=0;i<N;i++)
		{
			ll x;
			scanf("%lld",&x);
			v.push_back(x);
		}
		int cnt=0;
		sort(v.begin(),v.end(),greater<ll>());
		while(v.size()&&v.back()==0) {v.pop_back(); cnt++;}
		while(v.size()>1)
		{
			vector<ll> tmp; 
			for(int i=0;i<(int)v.size()-1;i++) tmp.push_back(v[i]-v[i+1]);
			if(cnt) {tmp.push_back(v.back()); cnt--;}
			swap(v,tmp); tmp.clear();
			sort(v.begin(),v.end(),greater<ll>());
			while(v.size()&&v.back()==0) {v.pop_back(); cnt++;}
		}
		if(!v.size()) puts("0"); else printf("%lld\n",v[0]);
	}
	return 0;
}