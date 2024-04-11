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
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,x[4];
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>s;
	rep(i,0,n-1){
		if(s[i]=='U')x[0]++;
		if(s[i]=='D')x[1]++;
		if(s[i]=='L')x[2]++;
		if(s[i]=='R')x[3]++;
	}
	cout<<min(x[0],x[1])*2+min(x[2],x[3])*2<<endl;
	return 0;
}