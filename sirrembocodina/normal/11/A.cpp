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

vector<int> a;

int main(){       
	int n,d,ans=0;
	cin>>n>>d;
	forn(i,n){
		int x;
		cin>>x;
		a.pb(x);
	}
	for(int i=1;i<n;i++)
		if(a[i]<=a[i-1]){
			ans+=(a[i-1]-a[i])/d+1;
			a[i]+=d*((a[i-1]-a[i])/d+1);
		}
	cout<<ans;
}