//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
char t[100005];
int k;
int n;
int freq[26];
bool ok[26];

vector<PII> arr;

void preprocess()
{

}

void solve()
{
	fill(freq,0);
	int n=strlen(t);
	for(int i=0;i<n;i++)
		freq[t[i]-'a']++;
		
	arr.clear();
	for(int i=0;i<26;i++)
		arr.pb(mp(freq[i],i));
	sort(arr.begin(),arr.end());
	
	fill(ok,false);
	int sum=0;
	int cnt=0;
	for(int i=25;i>=0;i--)
	{
		if(sum>=n-k) break;
		cnt++;
		sum += arr[i].first;
		ok[arr[i].second]=true;
		if(sum>=n-k) break;
	}
	
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
	{
		if(ok[t[i]-'a'])
			printf("%c",t[i]);
	}
	printf("\n");
	
}

bool input()
{
	scanf("%s",t);
	s(k);
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}