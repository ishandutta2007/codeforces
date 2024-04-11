#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 500005;
struct ans{
	int l, r, d;
	ans(int l = 0 , int r = 0, int d = 0):l(l), r(r), d(d){}
};
int a[MX], b[MX];
vector<ans> A;
int Tc, N;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		A.clear();
		cin >> N;
		for(i = 0 ; i < N ; i ++) cin >> a[i], b[i] = a[i];
		sort(b, b + N);
		for(i = 0 ; i < N ; i ++) {
			for(j = i ; j < N ; j ++)
				if(a[j] == b[i]) break;
			if(j == i) continue;
			A.push_back(ans(i + 1, j + 1, j - i));
			for(int k = j ; k > i ; k --) a[k] = a[k - 1];
			a[i] = b[i];
		}
		cout << A.size() << endl;
		for(auto Ans : A) cout << Ans.l << ' ' << Ans.r << ' ' << Ans.d << endl;
	}

	return 0;

}