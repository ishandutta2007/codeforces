#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int go[1100],come[1100],cap[1100];
int main()
{
	int i,n,m,a,b,c;vector <int> x,y,z;
	cin>>n>>m;
	for(i=0;i<1100;i++) go[i]=come[i]=-1;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		go[a]=b;come[b]=a;cap[a]=c;
	}
	for(i=1;i<=n;i++){
		if(come[i]!=-1 || go[i]==-1) continue;
		int ca=1100000,it=i;
		while(go[it]!=-1){
			ca=min(ca,cap[it]);it=go[it];
		}
		x.pb(i);y.pb(it);z.pb(ca);
	}
	cout<<x.size()<<endl;
	for(i=0;i<x.size();i++){
		printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}