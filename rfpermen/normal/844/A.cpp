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
int n,vis[200],cnt;
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s>>n;
	rep(i,0,s.size()-1){
		if(vis[s[i]]==0)cnt++;
		vis[s[i]]=1;
	}
	if(s.size()<n)cout<<"impossible"<<endl;
	else cout<<max(0,n-cnt)<<endl;
	return 0;
}