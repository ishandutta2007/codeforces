#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
typedef pair<int, int> pnt;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())

ll a[100];
ll b[100];
ll ans[100];


int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
	int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {    	
    	int x;
    	scanf("%d", &x);
    	int cnt = 0;
    	while (x > 0) {
    		if (x % 2 == 1) {
    			a[cnt]++;
    		}
    		x /= 2;
    		cnt++;
    	}
    }
    ll Ans = 0;
    for (int i = 0; i < m; i++) {
    	int x;
    	scanf("%d", &x);
    	b[x]++;		
    }
    ll tk = 0;
    for (int i = 60; i >= 0; i--) {
    	tk = tk * 2 + a[i];
    	ll dd = min(tk, b[i]);
    	ans[i] += dd;
    	tk -= dd;
    	b[i] -= dd;
    	Ans += dd;
    }
    for (int i = 60; i >= 0; i--) {
    	a:
    	if (ans[i] > 0) {
    		ll sum = 0;
    		for (int j = 0; j < i; j++) {
    			sum += b[j];
    		}
    		if (sum > 1) {
    			ans[i]--;
    			Ans--;
    			tk = 1;
    			for (int j = i - 1; j >= 0; j--) {
    				tk = tk * 2;
			    	ll dd = min(tk, b[j]);
			    	ans[j] += dd;
			    	tk -= dd;
			    	b[j] -= dd;
			    	Ans += dd;
    			}
    			goto a;
    		}
    	}
    }
    cout<<Ans<<endl;
	return 0;
}