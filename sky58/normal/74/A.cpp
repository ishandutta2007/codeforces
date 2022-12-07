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
typedef pair<int,string> pint;
int main()
{
	string s;int n,p,m,a,b,c,d,e,i;vector <pint> ret;
	cin>>n;
	for(i=0;i<50;i++){
		cin>>s>>p>>m>>a>>b>>c>>d>>e;ret.pb(mp(a+b+c+d+e+100*p-50*m,s));
	}
//	for(i=0;i<n;i++) cout<<ret[i].se<<' '<<ret[i].fi<<endl;
	sort(ret.begin(),ret.end());reverse(ret.begin(),ret.end());
	cout<<ret[0].se<<endl;
	return 0;
}