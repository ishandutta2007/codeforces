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
vector <lint> zyo;
lint dig(lint a){
	lint ret=0;
	while(a>0){
		a/=10;ret++;
	}
	return ret;
}
int main()
{
	lint i,a,b,out,da,db;cin>>a>>b;zyo.pb(0);
	for(i=0;i<12;i++) zyo.pb(zyo[i]*10+9);
	da=dig(a),db=dig(b);
	out=max(a*(zyo[da]-a),b*(zyo[db]-b));
	if(zyo[db]/2<=b && zyo[db]/2+1>=a) out=max(out,zyo[db]/2*(zyo[db]-zyo[db]/2));
	if(zyo[da]/2+1>=a && zyo[da]/2<=b) out=max(out,zyo[da]/2*(zyo[da]-zyo[da]/2));
	cout<<out<<endl;
	return 0;
}