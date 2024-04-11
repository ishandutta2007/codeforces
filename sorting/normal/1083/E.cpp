#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

long long fdiv(long long a, long long b){ // floored division
	return a / b - ((a ^ b) < 0 && a % b); 
}

struct convex_hull_trick{
	struct line{
		long long k, b;

		line(long long k, long long b){
			this->k = k;
			this->b = b;
		}

		long long eval(long long x){
			return k * x + b;
		}

		friend long double cross(line lvalue, line rvalue){
			return (long double)(rvalue.b - lvalue.b) / (lvalue.k - rvalue.k);
		}
	};

	vector<line> lines;

	

	bool bad(line l){
		if(l.k == lines[lines.size() -1].k){
			return true;
		}

		line pr1 = lines[lines.size() - 1];
		line pr2 = lines[lines.size() - 2];

		if(cross(l, pr2) >= cross(pr1, pr2)){
			return true;
		}

		return false;
	}

	// in decreasing order of k
	void add_line(long long k, long long b){
		line l = line(k, b);

		while(lines.size() >= 2 && bad(l)){
			lines.pop_back();
		}


		if(lines.empty() || lines.back().k != l.k){
			lines.push_back(l);
		}

		return ;
	}

	long long get(long long x){
		int l = 0, r = (int)lines.size() - 1;

		while(l != r){
			int mid = (l + r) / 2;

			if(lines[mid].eval(x) < lines[mid + 1].eval(x)){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}

		return lines[l].eval(x);
	}
};

struct rectangle{
	long long x, y, a;

	friend bool operator<(rectangle lvalue, rectangle rvalue){
		return lvalue.x > rvalue.x;
	}
};

rectangle r[N];
convex_hull_trick cht;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> r[i].x >> r[i].y >> r[i].a;
	}

	sort(r, r + n);

	long long res = 0;

	cht.add_line(0, 0);

	for(int i = 0; i < n; i++){
		long long value;

		value = cht.get(r[i].x);

		//cout << value << endl;

		res = max(res, value);
		cht.add_line(-r[i].y, value + r[i].x * r[i].y - r[i].a);
	}

	res = max(res, cht.get(0ll));

	cout << res << "\n";

	return 0;
}