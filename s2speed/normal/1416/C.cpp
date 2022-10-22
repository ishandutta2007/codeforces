#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 32 * 3e5;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

deque<ll> d , h;
ll p[MAX_N] , inv = 0 , x = 0 , n , z , y = 1;
vector<ll> v[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	z = tav(2 , 30);
	cin>>n;
	for(int i = 0 ; i < MAX_N ; i++){
		p[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		v[0].push_back(inp);
	}
	d.push_back(0);
	ll b = 0;
	while(z > 0){
		ll inv0 = 0 , inv1 = 0 , ds = d.size();
		for(int e = 0 ; e < ds ; e++){
			ll i = d.front();
			ll vs = v[i].size();
			for(int j = 0 ; j < vs ; j++){
				if((v[i][j] / z) % 2 == 0){
					p[i]++;
				}
			}
//			cout<<i<<"\n";
			h.push_back(i);
			d.pop_front();
		}
		ds += b;
//		cout<<ds<<" "<<b<<"\n";
		ll hs = h.size();
		for(int e = 0 ; e < hs ; e++){
			ll i = h.front();
//			cout<<i<<"\n";
			ll vs = v[i].size() , c0 = p[i] , c1 = vs - c0 , cinv = 0 , ctotal = (vs * (vs - 1) / 2) - (c1 * (c1 - 1) / 2) - (c0 * (c0 - 1) / 2) , r1 = -1 , r0 = -1;
//			cout<<vs<<" "<<c0<<" "<<c1<<" "<<ctotal<<"\n";
			for(int j = 0 ; j < vs ; j++){
				if((v[i][j] / z) % 2 == 1){
					if(r1 == -1){
						d.push_back(y);
						r1 = y;
						y++;
					}
					v[r1].push_back(v[i][j]);
					cinv += c0;
				} else {
					if(r0 == -1){
						d.push_back(y);
						r0 = y;
						y++;
					}
					v[r0].push_back(v[i][j]);
					c0--;
				}
			}
//			cout<<y<<"\n";
//			cout<<r0<<" "<<r1<<"\n";
//			cout<<cinv<<"\n";
			inv0 += cinv;
			inv1 += ctotal - cinv;
			h.pop_front();
		}
		if(inv1 < inv0){
			x += z;
			inv += inv1;
		} else {
			inv += inv0;
		}
		z /= 2;
		b = ds;
	}
	cout<<inv<<" "<<x<<"\n";
	return 0;
}