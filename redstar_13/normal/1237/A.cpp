#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	cin >> n;
	int f=0;
	for(int i=0; i<n; i++) {
			int u;
		cin >> u;
		if(u%2==0) cout<<u/2<<endl;
		else {
			if(f) {
				if(u<0) cout<<u/2<<endl;
				else cout<<(u+1)/2<<endl;
			}
			else {
				if(u<0) cout<<(u-1)/2<<endl;
				else cout<<u/2<<endl;
			}
			f^=1;
		}
	}
	return 0;
}