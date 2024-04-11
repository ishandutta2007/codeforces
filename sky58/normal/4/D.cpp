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
typedef pair<pint,int> qint;
vector <int> dp,ret;vector <qint> ke;
int main()
{
	int n,w,h,nw,nh,i,j,out=0;//vector <int> dp,ret;vector <qint> ke;
	cin>>n>>w>>h;nw=w;nh=h;
	for(i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ke.pb(mp(mp(a,b),i+1));
	}
	sort(ke.begin(),ke.end());reverse(ke.begin(),ke.end());
	for(i=0;i<n;i++){
		dp.pb(1);
		for(j=0;j<i;j++){
//			if(ke[j].fi.fi>ke[i].fi.fi && ke[j].fi.se>ke[i].fi.se) dp[i]>?=dp[j]+1;
			if(ke[j].fi.fi>ke[i].fi.fi && ke[j].fi.se>ke[i].fi.se){
				if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
			}
		}
	}
	for(i=0;i<n;i++){
//		if(ke[i].fi.fi>w && ke[i].fi.se>h) out>?=dp[i];
		if(ke[i].fi.fi>w && ke[i].fi.se>h){
			if(out<dp[i]) out=dp[i];
		}
	}
//	int ff=n-1;
	for(i=0;i<out;i++){
		for(j=0;j<n;j++){
//		while(1){
			if(ke[j].fi.fi>nw && ke[j].fi.se>nh && dp[j]>=out-i){
				ret.pb(ke[j].se);nw=ke[j].fi.fi;nh=ke[j].fi.se;break;
			}
//			ff--;
		}
	}
	cout<<out<<'\n';
	if(out>0){
		for(i=0;i<out-1;i++) cout<<ret[i]<<' ';
		cout<<ret[out-1]<<endl;
	}
	return 0;
}