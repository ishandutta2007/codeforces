#include <bits/stdc++.h>

using namespace std;

vector<int> min_right(vector<int>& a) {
	stack<int> s;
	vector<int> answer(a.size(), 0);
	for(int i=0; i<a.size(); i++) {
		while(!s.empty() && a[s.top()] > a[i]) {
			answer[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		answer[s.top()] = a.size();
		s.pop();
	}
	return answer;
}

vector<int> max_right(vector<int>& a) {
	stack<int> s;
	vector<int> answer(a.size(), 0);
	for(int i=0; i<a.size(); i++) {
		while(!s.empty() && a[s.top()] < a[i]) {
			answer[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		answer[s.top()] = a.size();
		s.pop();
	}
	return answer;
}

vector<int> mine_right(vector<int>& a) {
	stack<int> s;
	vector<int> answer(a.size(), 0);
	for(int i=0; i<a.size(); i++) {
		while(!s.empty() && a[s.top()] >= a[i]) {
			answer[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		answer[s.top()] = a.size();
		s.pop();
	}
	return answer;
}

vector<int> maxe_right(vector<int>& a) {
	stack<int> s;
	vector<int> answer(a.size(), 0);
	for(int i=0; i<a.size(); i++) {
		while(!s.empty() && a[s.top()] <= a[i]) {
			answer[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		answer[s.top()] = a.size();
		s.pop();
	}
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push_back(in);
		}
		int answer = 0;
		vector<int> mir = min_right(a);
		vector<int> mar = max_right(a);
		vector<int> mier = mine_right(a);
		vector<int> maer = maxe_right(a);
		int node = 0;
		while(node < n-1) {
			if(mir[node] < mar[node]) {
				int lim = mar[node];
				while(mier[node] < lim) {
					node = mier[node];
				}
			} else {
				int lim = mir[node];
				while(maer[node] < lim) {
					node = maer[node];
				}
			}
			answer++;
		}
		printf("%d\n", answer);
	}
}