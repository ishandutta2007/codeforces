#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n;
map<int, vector<int> > B;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int nn = n;
		// fac
		vector< pair<int,int> > vec, divs; 
		for (int i = 2; i * i <= n; i ++) {
			if (n % i == 0) {
				int c = 0;
				while (n % i == 0) {
					n /= i; c ++;
				}
				vec.push_back(make_pair(i, c));
			}	
		}
		if (n > 1) vec.push_back(make_pair(n, 1));
		// divs
		n = nn;
		set<int> d;
		for (int i = 1; i * i <= n; i ++) {
			if (n % i == 0) {
				if (i > 1) d.insert(i);
				if (i * i != n) {
					if (n / i > 1) d.insert(n / i);
				}
			}
		}
		// mn
		sort(vec.begin(), vec.end());
		B.clear();
		for (auto x: d) {
			//printf("div = %d\n", x);
			for (auto y: vec) {
				if (x % y.first == 0) {
					B[y.first].push_back(x); 
					//printf("%d => %d\n", y.first, x);
					break;
				}
			} 
		}
		if (vec.size() == 1) {
			for (auto x: d) printf("%d ", x);
			printf("\n");
			printf("0\n");
			continue;
		}

		if (vec.size() == 2) {
			vector<int> L,R,M;
			for(auto x:d){
				if(x%vec[0].first==0 && x%vec[1].first) L.push_back(x);
				if(x%vec[0].first==0 && x%vec[1].first==0) M.push_back(x);
				if(x%vec[1].first==0 && x%vec[0].first) R.push_back(x);
			}
			for(auto x:L) printf("%d ", x);
			for(int i=0;i<(int)M.size()-1;i++) printf("%d ", M[i]);
			for(auto x:R) printf("%d ", x);
			printf("%d\n", M.back());
			if(M.size()>=2)printf("0\n");else printf("1\n");
			continue;
		}

		vector<int> ans;
		for(int i=0;i<vec.size();i++){
			int j=i-1; if (j==-1) j=vec.size()-1;
			d.erase(vec[i].first * vec[j].first);
		}

		for(int i=0;i<vec.size();i++){
			int j=i-1; if (j==-1) j=vec.size()-1;
			ans.push_back(vec[i].first * vec[j].first); 
			for (auto x: B[vec[i].first]) {
				if(d.find(x) != d.end()) ans.push_back(x);
			}
		}
		for (auto x: ans) {
			printf("%d ", x);
		} printf("\n");
		printf("0\n");
	}		
}