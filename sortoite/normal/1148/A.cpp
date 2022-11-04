#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	INT a, b, c; cin>>a>>b>>c;
	INT ans;
	if(max(a, b)>min(a, b)) ans=min(a, b)*2+1;
	else ans=min(a, b)*2;
	
	cout<<ans+c*2;
}