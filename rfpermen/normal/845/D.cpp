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
int n,idx,x,ans,cnt,spd,s1,s2,mx,le;
stack<int> pas;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	mx=1000;
	rep(i,1,n){
		cin>>idx;
		if(idx==1){
			cin>>x;
			spd=x;
			if(spd>mx){
				while(!pas.empty()){
					if(spd>pas.top())ans++, pas.pop();
					else break;
				}
			}
		}
		if(idx==2){
			if(s2)ans+=le, le=0;
		}
		if(idx==3){
			cin>>x;
			mx=x;
			s1=0;
			if(spd>mx)s1=1, ans++;
			else pas.push(mx);
		}
		if(idx==4){
			s2=0, le=0;
		}
		if(idx==5){
			mx=1000;
			while(!pas.empty()){
					pas.pop();
			}
		}
		if(idx==6){
			s2=1;
			le++;
		}
	}
	cout<<ans<<endl;
	return 0;
}