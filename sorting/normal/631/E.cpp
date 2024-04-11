#include <bits/stdc++.h>

using namespace std;

struct convex_hull_trick{
	struct line{
		long long k, b;

		line(){}
		line(long long k, long long b){
			this->k = k;
			this->b = b;
		}
	};

	vector<line> v;

	long long eval(line l, long long x){
		return l.k * x + l.b;
	}

	long long cross(line lvalue, line rvalue){
		return (rvalue.b - lvalue.b) / (lvalue.k - rvalue.k);
	}

	bool bad(line l){
		if(l.k == v.back().k){
			if(l.b >= v.back().b){
				return true;
			}
			
			return false;
		}

		line pr1 = v[v.size() - 1];
		line pr2 = v[v.size() - 2];

		if(cross(l, pr2) > cross(pr1, pr2)){
			return true;
		}

		return false;
	}

	void add_line(long long k, long long b){
		line l(k, b);

		while(v.size() >= 2 && bad(l)){
			v.pop_back();
		}
		if(v.empty() || v.back().k != l.k || l.b > v.back().b){
			v.push_back(l);
		}
	}

	long long get(long long x){
		int l = 0, r = (int)v.size() - 1;

		while(l != r){
			int mid = (l + r) >> 1;

			if(eval(v[mid], x) < eval(v[mid + 1], x)){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}

		return eval(v[l], x);
	}
};

const int N = 2e5 + 7;
const long long inf = 1e18;

long long a[N], sum[N];
convex_hull_trick cht;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	long long x = 0;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
		x += a[i] * i;
	}

	long long ans = -inf;

	for(long long i = n; i >= 1; i--){
		cht.add_line(i, -sum[i]);
		ans = max(ans, cht.get(a[i]) + sum[i] - a[i] * i);
		//cout << cht.get(a[i]) + sum[i] - a[i] * i << " i " << i  << endl;
	}
	cht.v.clear();

	//cout << ans << endl;

	for(long long i = 1; i <= n; i++){
		cht.add_line(-i, -sum[i - 1]);
		ans = max(ans, cht.get(-a[i]) + sum[i - 1] - a[i] * i);

		//cout << cht.get(-a[i]) + sum[i - 1] - a[i] * i << " i " << i  << endl;
	}

	//cout << ans << endl;

	cout << ans + x << "\n";

	return 0;
}