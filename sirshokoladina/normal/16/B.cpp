#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main(){
	vector<pair<int,int> > a;
	int n,m;
	cin>>n>>m;
	swap(n,m);
	forn(i,n){
		int x,y;
		cin>>x>>y;
		a.pb(mp(y,x));
	}
	sort(a.begin(),a.end());
	long long ans=0;
	for(int i=a.size()-1;i>=0 && m>0;i--){
		int k=min(m,a[i].sc);
		ans+=k*a[i].fs;
		m-=k;
	}
	cout<<ans;
	return 0;
}