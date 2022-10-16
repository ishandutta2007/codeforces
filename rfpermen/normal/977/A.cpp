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
const int MAX=100005;
const int MOD=1000000000 + 7;
ll n,x;

int main(){
	cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>x;
	rep(i,1,x){
		if(n%10==0)n/=10;
		else n--;
		//cout<<n<<endl;
	}
	cout<<n<<endl;
	return 0;
}