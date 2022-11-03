#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int a,b,c;
int m;
vector<ll> jq[2];
char __b__[100];

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int X;
		scanf("%d %s",&X,__b__);
		if(__b__[0]=='U') jq[0].push_back(X);
		else jq[1].push_back(X);
	}
	ll AA=0,BB=0;
	sort(jq[0].begin(),jq[0].end());
	sort(jq[1].begin(),jq[1].end());
	for(int i=0;i<(int)jq[0].size()-1;i++)
		jq[0][i+1]+=jq[0][i];
	for(int i=0;i<(int)jq[1].size()-1;i++)
		jq[1][i+1]+=jq[1][i];
	for(int i=0;i<=min(a+c,(int)jq[0].size());i++)
	{
		int x=min((ll)jq[1].size(),(ll)a+(ll)c-(ll)max((ll)i,(ll)a)+(ll)b);
		ll Bb=0;
		if(x!=0) Bb+=jq[1][x-1];
		if(i!=0) Bb+=jq[0][i-1];
		if((ll)x+(ll)i>AA||((ll)x+(ll)i==AA && Bb<BB)) AA=x+i,BB=Bb;
	}
	cout<<AA<<' '<<BB<<endl;
	return 0;
}