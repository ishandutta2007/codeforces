#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 1000006; 

int n, m; 
char s[maxn]; 
int f[maxn]; 
int a[maxn]; 
int sum[maxn]; 

bool check(int l, int r) {
	if (l > r) return true; 
	return sum[r]-sum[l-1] == 0; 
}

int main() {
	scanf("%d", &n); 
	scanf("%s", s + 1); 
	sum[0] = 0; 
	for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + (s[i]=='*'); 
	m = 0; 
	for (int i = 1; i <= n; ++i) 
		if (s[i] == 'P') a[++m] = i; 
	if (m == 1) {
		int mini = n+1, maxi = 0; 	
		for (int i = 1; i <= n; ++i) 
			if (s[i] == '*') {
				mini = min(mini, i);
				maxi = max(maxi, i); 
			}
		int A = sum[a[1]], B = sum[n]-sum[a[1]]; 
		if (A > B) cout<<A<<' '<<a[1]-mini<<endl; 
		else if (A < B) cout<<B<<' '<<maxi-a[1]<<endl; 
		else if (a[1]-mini < maxi-a[1]) cout<<A<<' '<<a[1]-mini<<endl; 
		else cout<<B<<' '<<maxi-a[1]<<endl; 
		return 0; 
	}
	int L = 0, R = n+1; 
	while (L + 1 < R) {
		int d = ((L + R) >> 1);
		f[0] = 0;  
		bool flag = true; 
		for (int i = 1; i <= m; ++i) 
			if (!check(f[i-1]+1, a[i]-d-1)) {flag = false; break;}
			else if (check(f[i-1]+1, a[i]-1)) f[i] = a[i]+d; 
			else if (i > 1 && check(f[i-2]+1, a[i]-d-1)) f[i] = max(a[i-1]+d,a[i]);   
			else f[i] = a[i]; 
		if (flag && check(f[m]+1,n)) R = d; 
		else L = d;  
	}
	cout<<sum[n]<<' '<<R<<endl; 
}