#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
int n,aa,bb;
bool a,b;
pii x[MAX];
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i].fi>>x[i].se;
	sort(x+1,x+1+n);
	rep(i,1,n){
		if(a==0)a=1, aa=x[i].se;
		else if(aa<x[i].fi)aa=x[i].se;
		else if(b==0)b=1, bb=x[i].se;
		else if(bb<x[i].fi)bb=x[i].se;
		else {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}