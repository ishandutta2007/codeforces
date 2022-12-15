#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;
const int kInf = 1e9;

struct SuffixAutomaton{
	struct State{
		int len, link;
		map<char, int> next;

		State(){}
	};
	State st[2 * kN];
	int sz, last;

	SuffixAutomaton(){
		sz = 1;
		last = 0;
		st[0].len = 0;
		st[0].link = -1;
	}

	void extend(char c){
		int curr = sz++;
		st[curr].len = st[last].len + 1;

		int p = last;
		while(p != -1 && !st[p].next.count(c)){
			st[p].next[c] = curr;
			p = st[p].link;
		}

		if(p == -1)
			st[curr].link = 0;
		else{
			int q = st[p].next[c];
			if(st[p].len + 1 == st[q].len)
				st[curr].link = q;
			else{
				int clone = sz++;
				st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;
				st[clone].link = st[q].link;

				while(p != -1 && st[p].next[c] == q){
					st[p].next[c] = clone;
					p = st[p].link;
				}

				st[q].link = st[curr].link = clone;
			} 
		}

		last = curr;
	}
};

SuffixAutomaton sa;

vector<int> nodes[kN];
int dp[2 *kN], cnt[2 *kN];
bool used[2 *kN];

void dp_rec(int u){
	if(used[u])
		return;
	used[u] = 1;
	dp[u] = cnt[u];

	for(auto it: sa.st[u].next){
		dp_rec(it.second);
		dp[u] += dp[it.second];
		if(dp[u] >= kInf)
			dp[u] = kInf;
	}
}

string tmp;
string solve(int u, int k){
	if(k <= cnt[u])
		return tmp;

	k -= cnt[u];
	for(auto it: sa.st[u].next){
		if(k <= dp[it.second]){
			tmp += it.first;
			return solve(it.second, k);
		}

		k -= dp[it.second];
	}

	return "NO";
}

string get_answer(const string &s, const int &k){
	int n = s.size();
	if((long long)n * (long long)(n + 1) / 2 < k)
		return "No such line.";

	for(int i = 0; i < s.size(); ++i){
		sa.extend(s[i]);
		cnt[sa.last]++;
	}

	for(int i = 0; i < sa.sz; ++i)
		nodes[sa.st[i].len].push_back(i);

	for(int len = kN - 1; len >= 1; --len){
		for(int idx: nodes[len]){
			if(sa.st[idx].link){
				cnt[sa.st[idx].link] += cnt[idx];
				if(cnt[sa.st[idx].link] >= kInf)
					cnt[sa.st[idx].link] = kInf;
			}
		}
	}

	dp_rec(0);
	return solve(0, k);
}

void read(string &s, int &k){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> k;
}

string s;
int k;

int main(){
	read(s, k);
	cout << get_answer(s, k) << "\n";
}