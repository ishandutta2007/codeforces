#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

ll cross(ll x1, ll y1, ll x2, ll y2){
	return x1*y2-x2*y1;
}

int main(){
	int n; cin >> n;
	ll dx1, dy1, dx2, dy2; cin >> dx1 >> dy1 >> dx2 >> dy2;
	if(abs(cross(dx1,dy1,dx2,dy2)) != n){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	if(cross(dx1,dy1,dx2,dy2) > 0){
		swap(dx1,dx2);
		swap(dy1,dy2);
	}
	queue<pair<ll,ll>> Q;
	Q.push({0,0});
	set<pair<ll,ll>> S;
	while(Q.size()){
		auto [x,y] = Q.front();
		Q.pop();
		{
			ll l = -(1ll<<30), r = 1ll<<30;
			ll bes = 0;
			while(l <= r){
				ll m = (l+r)>>1;
				if(cross(x+dx1*m,y+dy1*m,dx2,dy2) > 0){
					l = m+1;
					bes = m;
				}
				else{
					r = m-1;
				}
			}
			x+=dx1*bes, y+=dy1*bes;
		}
		{
			ll l = -(1ll<<30), r = 1ll<<30;
			ll bes = 0;
			while(l <= r){
				ll m = (l+r)>>1;
				if(cross(x+dx2*m,y+dy2*m,dx1,dy1) > 0){
					r = m-1;
					bes = m;
				}
				else{
					l = m+1;
				}
			}
			x+=dx2*bes, y+=dy2*bes;
		}
		if(S.count({x,y}))continue;
		S.insert({x,y});
		for(int i = 0; i < 4; ++i){
			Q.push({x+dx[i],y+dy[i]});
		}
	}
	for(auto x : S)cout << x.first << ' ' << x.second << '\n';
}