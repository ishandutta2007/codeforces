#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

char s[111];
int a[111], b[111];

int calc(int t, int ok, int a, int b) {
	if (t<b) return ok;
	return ok^((t-b)%(2*a)<a);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif

	int n;
	cin>>n>>(s+1);
	for (int i=1; i<=n; i++) scanf("%d%d", a+i, b+i);
	
	int ans = count(s+1, s+n+1, '1');
	for (int t=1; t<=100000; t++) {
		int cnt = 0;
		for (int i=1; i<=n; i++) cnt+=calc(t, s[i]-'0', a[i], b[i]);
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);

	return 0;
}