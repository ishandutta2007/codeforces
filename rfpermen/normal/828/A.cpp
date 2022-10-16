#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=1005;
ll gcd(ll r,ll v){
	if(v==0) return r;
	return gcd(v,r%v);
}
ll n,a,b,x,cnt,tmp;
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	rep(i,1,n){
		cin>>x;
		if(x==1 && a>0)a--;
		else if(x==1 && b>0)tmp++, b--;
		else if(x==1 && tmp>0)tmp--;
		else if(x==2 && b>0)b--;
		else cnt+=x;
	}
	cout<<cnt<<endl;
	return 0;
}