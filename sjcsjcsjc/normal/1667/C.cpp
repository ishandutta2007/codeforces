#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	int k=(2*n+1)/3;
	cout<<k<<'\n';
	int x=(k+1)/2;
	for(int i=1;i<=x;i++) cout<<i<<' '<<x+1-i<<'\n';
	int y=(k-1)/2;
	for(int i=1;i<=y;i++) cout<<x+i<<' '<<x+y+1-i<<'\n';
	if(k%2==0) cout<<k<<' '<<k<<'\n';
	return 0;
}