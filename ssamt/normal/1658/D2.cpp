#include <bits/stdc++.h>

using namespace std;

int s = 17;

vector<int> solve_d1(int l, int r, vector<int>& a) {
	int i, j;
	vector<int> answer{0};
	for(i=s-1; i>=0; i--) {
		int count = 0, count2 = 0;
		for(j=0; j<a.size(); j++) {
			if(a[j]&(1<<i)) {
				count++;
			}
			if((j+l)&(1<<i)) {
				count2++;
			}
		}
		if(count == count2) {
			//cout << i;
			if(a.size()-count == count2) {
				int save = answer.size();
				for(j=0; j<save; j++) {
					answer.push_back(answer[j]^(1<<i));
				}
			}
		} else {
			for(j=0; j<answer.size(); j++) {
				answer[j] ^= (1<<i);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int solve_d2(int l, int r, vector<int>& a) {
	if(l == 0) {
		return solve_d1(l, r, a)[0];
	}
	int i, j;
	int div, dig;
	for(i=s-1; i>=0; i--) {
		if((l-1)/(1<<i) != (r-1)/(1<<i)) {
			div = (r-1)/(1<<i)*(1<<i);
			dig = i;
			break;
		}
	}
	//cout << dig;
	int count = 0;
	for(int num:a) {
		if(num&(1<<dig)) {
			count++;
		}
	}
	vector<int> small;
	for(i=0; i<a.size(); i++) {
		if(!(a[i]&(1<<dig))) {
			small.push_back(a[i]);
			//cout << "sm" << a[i] << " ";
		}
	}
	vector<int> large;
	for(i=0; i<a.size(); i++) {
		if(a[i]&(1<<dig)) {
			large.push_back(a[i]);
			//cout << "lr" << a[i] << " ";
		}
	}
	vector<int> sm_ans, lr_ans;
	//cout << count << div << dig << l << endl;
	if(count == div-l) {
		//cout << "rev";
		if(small.empty()) {
			return solve_d1(0, r-l, large)[0]^(div-1);
		}
		if(large.empty()) {
			return solve_d1(0, r-l, small)[0]^div;
		}
		sm_ans = solve_d1(0, div-l, large);
		lr_ans = solve_d1(0, r-div, small);
	} else {
		if(small.empty()) {
			return solve_d1(0, r-l, large)[0]^div;
		}
		if(large.empty()) {
			return solve_d1(0, r-l, small)[0]^(div-1);
		}
		sm_ans = solve_d1(0, div-l, small);
		lr_ans = solve_d1(0, r-div, large);
	}
	for(i=0; i<sm_ans.size(); i++) {
		sm_ans[i] ^= (div-1);
	}
	for(i=0; i<lr_ans.size(); i++) {
		lr_ans[i] ^= div;
	}
	sort(sm_ans.begin(), sm_ans.end());
	sort(lr_ans.begin(), lr_ans.end());
	/*for(int num:sm_ans) {
		cout << num << " ";
	}
	cout << endl;
	for(int num:lr_ans) {
		cout << num << " ";
	}*/
	//cout << endl;
	for(i=0, j=0; sm_ans[i]!=lr_ans[j];) {
		if(sm_ans[i] < lr_ans[j]) {
			i++;
		} else {
			j++;
		}
	}
	return sm_ans[i];
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		int l, r;
		cin >> l >> r;
		r++;
		vector<int> a(r-l);
		for(i=0; i<r-l; i++) {
			cin >> a[i];
		}
		cout << solve_d2(l, r, a) << endl;
	}
}