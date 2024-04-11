#include<bits/stdc++.h>
typedef long long ll;
const ll inf = 3e18;
int n, t;
struct T
{
	ll x, y, z;
};
std::vector<T> vec;
inline void up(ll & x,ll y)
{
	if(x < y) x = y;
}
inline void down(ll & x,ll y)
{
	if(x > y) x = y;
}
inline T check(ll mid)
{
	ll l0 = -inf, l1 = -inf, l2 = -inf, l3 = -inf;
	ll r0 = inf, r1 = inf, r2 = inf, r3 = inf;
	for(const auto & t : vec)
	{
		down(r0, mid + t.x + t.y + t.z);
		down(r1, mid - t.x + t.y + t.z);
		down(r2, mid + t.x - t.y + t.z);
		down(r3, mid + t.x + t.y - t.z);
		up(l0,-mid + t.x + t.y + t.z);
		up(l1,-mid - t.x + t.y + t.z);
		up(l2,-mid + t.x - t.y + t.z);
		up(l3,-mid + t.x + t.y - t.z);
	}
	for(int r = 0;r < 2;++r) {
		ll L0 = l0 - r * 3 + 1 >> 1,R0 = r0 - r * 3 >> 1;
		ll L1 = l1 - r + 1 >> 1,R1 = r1 - r >> 1;
		ll L2 = l2 - r + 1 >> 1,R2 = r2 - r >> 1;
		ll L3 = l3 - r + 1 >> 1,R3 = r3 - r >> 1;
		if(L0 <= R0 && L1 <= R1 && L2 <= R2 && L3 <= R3 && L1 + L2 + L3 <= R0 && L0 <= R1 + R2 + R3) {
			ll add = L0 - L1 - L2 - L3;
			if(add > 0) { ll dt = std::min(add,R1 - L1); add -= dt; L1 += dt; }
			if(add > 0) { ll dt = std::min(add,R2 - L2); add -= dt; L2 += dt; }
			if(add > 0) { ll dt = std::min(add,R3 - L3); add -= dt; L3 += dt; }
			ll a = L1 * 2 + r,b = L2 * 2 + r,c = L3 * 2 + r;
			return (T) {b + c >> 1,a + c >> 1,a + b >> 1};
		}
	}
	return (T) {-inf, 0, 0};
}
int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> t;
	while(t --) 
	{
		vec.clear(), std::cin >> n;
		for(T x;n--;)
		{
			std::cin >> x.x >> x.y >> x.z;
			vec.push_back(x);
		}
		ll l = -1,r = inf;
		for(;l + 1 != r;)
		{
			ll mid = l + r >> 1;
			if(check(mid).x != -inf) r = mid;
			else l = mid;
		}
		auto x = check(r);
		std::cout << x.x << ' ' << x.y << ' ' << x.z <<'\n';
	}
}