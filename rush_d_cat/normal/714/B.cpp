#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 1000005
typedef __int64 ll;

set<ll> s;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		ll tmp;cin>>tmp;
		s.insert(tmp);
	}
	int sz = s.size();
	if(sz<=2) cout<<"YES";
	if(sz==3){
		ll a[4],cnt=1;
		set<ll>::iterator it; //
		for(it=s.begin();it!=s.end();it++)
			a[cnt++] = *it;
		sort(a+1, a+4);
		if(a[1]+a[3]==2*a[2]) cout<<"YES";
		else cout<<"NO";
	}
	if(sz>=4){
		cout<<"NO";
	}
}