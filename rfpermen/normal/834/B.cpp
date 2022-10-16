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
int c,n,a,b,cnt;
int x[100];
bool stat,y[100];
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>s;
	rep(i,0,s.size()-1)x[s[i]-64]++;
	rep(i,0,s.size()-1){
		if(y[s[i]-64]==0)cnt++;
		if(cnt>n)stat=1;
		y[s[i]-64]=1;
		x[s[i]-64]--;
		if(x[s[i]-64]==0)cnt--;
		
	}
	if(stat)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}