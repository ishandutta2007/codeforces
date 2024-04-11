#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

ll t0, t1, t2, a1, a2, p1, p2;

ll gao(ll F, ll T){
	int lim = F / a1;
	ll ans = 1ll << 60;
	if (T < 0) return 1ll << 60;
	ll ind = F * t0 - T;
	//cout << "PPP :: " << lim << ' ' << F << ' ' << T << ' ' << ind << a1 * (t0 - t1) << endl;
	if (ind <= 0)
		return 0ll;
	ll den = a1 * (t0 - t1);
	ll cnt = (ind / den) + (ind % den != 0);
	if (0 <= cnt && cnt <= lim)
		ans = min(ans, cnt * p1);
	if (F % a1 != 0){
		if (t1 * F <= T){
			ans = min(ans, (lim + 1) * p1);
		}
	}
	//cout << "GAO :: " << F << ' ' << T << ' ' << ans << endl;
	return ans;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	ll F, T;
	scanf("%lld%lld%lld", &F, &T, &t0);
	scanf("%lld%lld%lld", &a1, &t1, &p1);
	scanf("%lld%lld%lld", &a2, &t2, &p2);
	ll ans = 1ll << 60;
	if (t1 >= t0 && t2 >= t0){
		if (t0 * F <= T)
			ans = 0;
	}
	else if (t2 >= t0){
		ans = gao(F, T);
	}
	else if (t1 >= t0){
		swap(t1, t2); swap(a1, a2); swap(p1, p2);
		ans = gao(F, T);
	}
	else{
		if (t1 < t2){
			swap(t1, t2); swap(a1, a2); swap(p1, p2);
		}
		// t1 >= t2
		int lim = F / a2;
		int lim2 = T / t2 / a2;
	//	cout << "!!! " << lim << endl;
	//	cout << a1 << ' ' << t1 << ' ' << p1 << endl;
	//	cout << a2 << ' ' << t2 << ' ' << p2 << endl;
		for (int i = 0; i <= lim && i <= lim2; i++){
			ans = min(ans, p2 * i + gao(F - a2 * i, T - t2 * a2 * i));
	//		cout << i << ' ' << ans << endl;
		}
		if (F % a2 != 0){
			if (t2 * F <= T){
				ans = min(ans, (lim + 1) * p2);
			}
		}
	}
	if (ans >= 1ll << 60)
		puts("-1");
	else
		printf("%lld\n", ans);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}