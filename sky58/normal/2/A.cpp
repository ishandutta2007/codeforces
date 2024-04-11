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
typedef pair<string,int> pint;
typedef pair<int,string> sint;
int n;
map<string,int> kei,to;
string cal(vector <pint> a){
	vector <sint> b;int i;
	for(i=0;i<n;i++) kei[a[i].fi]+=a[i].se;
	map<string,int>::iterator it=kei.begin();
	while(it!=kei.end()){
		b.pb(mp((*it).se,(*it).fi));++it;
	}
	sort(b.begin(),b.end());reverse(b.begin(),b.end());
	if(b.size()==1) return b[0].se;
	if(b[0].fi>b[1].fi) return b[0].se;
	for(i=0;i<n;i++){
		to[a[i].fi]+=a[i].se;
		if(to[a[i].fi]>=b[0].fi && kei[a[i].fi]>=b[0].fi) return a[i].fi;
	}
}
int main()
{
	vector <pint> a;
	int i;
	cin>>n;
	for(i=0;i<n;i++){
		int in;string st;cin>>st>>in;
		a.pb(mp(st,in));
	}
	cout<<cal(a)<<endl;
	return 0;
}