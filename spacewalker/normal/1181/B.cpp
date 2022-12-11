#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100'050;

char num[NMAX];
int l;

vector<int> getPDigList(int sstart) {
	vector<int> num1, num2;
	for (int i = sstart - 1; i >= 0; --i) {
		num1.push_back(num[i] - '0');
	}
	for (int i = l - 1; i >= sstart; --i) {
		num2.push_back(num[i] - '0');
	}
	if (num2.size() < num1.size()) swap(num1, num2); // WLOG num1 has smaller digcount
	int carry = 0;
	vector<int> res;
	for (int i = 0; i < num2.size(); ++i) {
		int cval = (i < num1.size() ? num1[i] : 0) + num2[i] + carry;
		res.push_back(cval % 10);
		carry = cval / 10;
	}
	reverse(begin(res), end(res));
	return res;
}

vector<int> findLesser(vector<int> &a, vector<int> &b) {
	if (a.size() != b.size()) return (a.size() > b.size() ? b : a);
	else {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) {
				return (a[i] > b[i] ? b : a);
			}
		}
	}
	return a;
}
void printAns(vector<int> &ans) {
	for (int d : ans) printf("%d", d);
	printf("\n");
}

int main() {
	scanf("%d", &l);
	scanf("%s", num);
	// if there are 2 partitions A, B, the most digits of the sum of maxlen(A) + 1 or maxlen(A)
	// so if maxlen(A) + 2 <= maxlen(B), A is the better partition
	// so 
	vector<pair<int, int>> byMaxLen;
	for (int ss = 1; ss < l; ++ss) {
		// the maxlen is max(ss, l - ss - 1);
		if (num[ss] != '0') byMaxLen.emplace_back(max(ss, l - ss - 1), ss);
	}
	vector<int> ans;
	sort(begin(byMaxLen), end(byMaxLen));
	for (int bmc = 0; bmc < min(4, (int)byMaxLen.size()); ++bmc) {
		if (ans.empty()) {
			ans = getPDigList(byMaxLen[bmc].second);
		} else {
			vector<int> cans = getPDigList(byMaxLen[bmc].second);
			ans = findLesser(ans, cans);
		}
//		printf("tried bmc %d ans: ", byMaxLen[bmc].second);
//		printAns(ans);
	}
	printAns(ans);
	return 0;
}