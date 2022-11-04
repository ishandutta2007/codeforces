#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

INT a[202020];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, k; scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) scanf("%I64d", a+i);
	
	INT pre=0, ans=0;
	for(int i=1; i<=n; i++) {
		if((pre+a[i])/k*k<pre) {
			ans+=(pre+a[i]+k-1)/k;
			pre=0;
		}
		else {
			ans+=(pre+a[i])/k;
			pre=(pre+a[i])%k;
		}
	}
	if(pre) ans++;
	cout<<ans<<endl;
}