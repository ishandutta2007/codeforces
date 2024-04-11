#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define I inline
using namespace std;

const int M=1e7+5;
const int N=1e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod1=1e9+7;
const int mod2=998244353;


signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int x,y,k;
		cin>>x>>y>>k;
		int q=y*k+k;//stick 
		cout<<(q-1+x-2)/(x-1)+k <<endl;
	}
}