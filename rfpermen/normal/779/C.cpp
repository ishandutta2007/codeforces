#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
pair<int,pair<int,int> > x[300000];
int n,k,a,b,c;
int main(){
	cin>>n>>k;
	rep(i,n)cin>>x[i].se.fi;
	rep(i,n)cin>>x[i].se.se;
	rep(i,n)x[i].fi=x[i].se.fi-x[i].se.se;
	sort(x+1,x+n+1);
	rep(i,k)c+=x[i].se.fi;
	if(k<n){
		for(int i=k+1;i<=n;i++){
			if(x[i].fi<0)c+=x[i].se.fi;
			else c+=x[i].se.se;
		}
	}
	cout<<c<<endl;
	return 0;
}