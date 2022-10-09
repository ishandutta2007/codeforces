#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

vector<pair<int,int> > x;

int main(){       
	int n,p1,p2,p3,t1,t2;                        
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	int ans=0;
	forn(i,n){
		int l,r;
		cin>>l>>r;
		x.pb(mp(l,r));
		ans+=(r-l)*p1;
	}
	forn(i,n-1){
		int t=x[i+1].fs-x[i].sc;
		ans+=min(t1,t)*p1;
		t-=t1;
		if(t<=0)
			continue;
		ans+=min(t2,t)*p2;
		t-=t2;
		if(t<=0)
			continue;
		ans+=t*p3;
	}
	cout<<ans;
}