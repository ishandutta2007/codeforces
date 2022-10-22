#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 cout.precision(30);
	 int t;
	 cin >> t;
	 while(t--) {
			int n, l;
			cin >> n >> l;
			vector<int>a(n);
			for(auto&x:a)
				cin >> x;
			vector<double>t1(n),t2(n);
			double pos=0,speed=1,tm=0;
			for(int i=0;i<n;++i) {
				tm += (a[i]-pos)/speed;
				speed += 1;
				pos = a[i];
				t1[i] = tm;
			}
			pos=l,speed=1,tm=0;
			for(int i=n-1;i>=0;--i) {
				tm += (pos-a[i])/speed;
				speed += 1;
				pos=a[i];
				t2[i]=tm;
			}
			double ans=1e18;
			for(int i=-1;i<n;++i){
				int pos1 = i==-1 ? 0 : a[i];
				int pos2=i==n-1? l : a[i+1];
				double speed1=i+2;
				double speed2=n-i;
				double tm2 = i == n - 1 ? 0 : t2[i+1];
				double tm1 = i == -1 ? 0 : t1[i];
				double rhs = pos1 / speed1 + pos2 / speed2 + tm2 - tm1;
				double x = rhs/(1/speed1 + 1/speed2);
				ans = min(ans, tm1 + (x - pos1) / speed1);
			}
			cout << ans << '\n';
	 }
	 return 0;
}