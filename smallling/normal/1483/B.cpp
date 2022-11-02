#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];
vector<int> ans;
set<pair<long long , int> > B;
set<int> A;
set<pair<long long, int> >::iterator Bit;
set<int>::iterator Ait;

int gcd(int a, int b) {
	if(a % b == 0)return b;
	return gcd(b, a % b);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		ans.clear();
		A.clear();
		B.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]), A.insert(i);
		for(int i = 0; i < n; i++)
			if(gcd(a[i], a[(i + 1) % n]) == 1) {
				B.insert(make_pair(i, (i + 1) % n));
			}
		while(B.size()) {
			Bit = B.begin();
			int cur = (*Bit).second;
			long long cul = (*Bit).first;
			ans.push_back(cur);
			B.erase(Bit);
			A.erase(cur);
			if(!A.size())break;
			Ait = A.lower_bound(cur);
			if(Ait == A.end())Ait = A.begin();
			int r = *Ait;
			Ait = A.lower_bound(cur);
			if(Ait == A.begin())Ait = A.end();
			Ait--;
			int l = *Ait;
			pair<int, int> tmp = make_pair(cur, 0);
			Bit = B.lower_bound(tmp);
			if(Bit != B.end() && (*Bit).second == r) {
				B.erase(Bit);
			}
			if(gcd(a[l], a[r]) == 1) {
				B.insert(make_pair(cul + n + 1, r));
				//printf("%d %d\n", l, r);
			}
		}
		if(!ans.size()) {
			printf("%d\n", ans.size());
		}
		else {
			printf("%d", ans.size());
			for(int i = 0; i < ans.size(); i++)
				printf(" %d", ans[i] + 1);
			puts("");
		}
	}
}