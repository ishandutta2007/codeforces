#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

map<int , int> mp;
vector<int> v;
int a[MAXN] , b[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int m , ind = -1;
	pii mx = {-1 , -1};
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	for(int i = 0 ; i < m ; i++){
		int c , cn = mp[b[i]] , ct;
		cin>>c; ct = mp[c];
		pii p = {cn , ct};
		if(p > mx){
			ind = i;
			mx = p;
		}
	}
	cout<<ind + 1<<'\n';
	return 0;
}

/*

*/