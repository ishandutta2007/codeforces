#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
const ll maxn=600;
ll score[maxn];
int main()
{
	ll Max=-10;deque<ll> d;
	ll n,k;cin>>n>>k;for(ll i=0;i<n;i++) {ll x;cin>>x;Max=max(Max,x);d.PB(x);} 
	while(d[0]!=Max)
	{
		ll a=d[0],b=d[1];d.pop_front();d.pop_front();
		if(a<b) {d.push_back(a);d.push_front(b);if(++score[b]==k) {cout<<b;return 0;}}
		else {d.push_back(b);d.push_front(a);if(++score[a]==k) {cout<<a;return 0;}}
	}
	cout<<Max;
}