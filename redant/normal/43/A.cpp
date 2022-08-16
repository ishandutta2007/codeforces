#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI ({int x;scanf("%d",&x);x;})

int n,m,N,M;

int main()
{
	int i,j,k;
	n=SI;
	
	string s1,s2,s;
	int c1=0,c2=0;

	cin>>s1; c1=1; n--;

	while(n--)
	{
		cin>>s;
		if(s==s1) c1++;
		else{ s2=s; c2++; }
	}
	
	if(c1>c2) cout<<s1; else cout<<s2;
	cout<<endl;

	return 0;
}