#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll FMD(ll x, ll m) {
	return ((x % m) + m) % m;
}

string tolower(string s) {
	string ans(s);
	for (int i = 0; i < ans.size(); ++i) {
		if (('A' <= ans[i]) && (ans[i] <= 'Z')) {
			ans[i] = (ans[i] - 'A') + 'a';
		}
	}
	return ans;
}

class SubstringHash {
	ll b;
	ll m;
	vector<int> prefHash;
	int n;
public:
	vector<ll> basePowers;
	SubstringHash(string s, int base, int mod) : b( base), m(mod), prefHash(s.size(), 0), n(s.size()) {
		basePowers = vector<ll>(n, 0);
		prefHash[0] = s[0];
		basePowers[0] = 1;
		for (int i = 1; i < n; ++i) {
			prefHash[i] = FMD(s[i] + FMD((prefHash[i-1] * b), m), m);
			basePowers[i] = (basePowers[i-1] * b) % m;
		}
	}
	ll getHash(int i, int j) {
		if (i == 0) {
			return prefHash[j];
		}
		return FMD(prefHash[j] - FMD(basePowers[j-i+1]*prefHash[i-1], m), m);
	}
	int operator() (string s) {
		ll ans = 0;
		for (char c : s) {
			ans = (((ans * b) % m) + c) % m;
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	string ctext; cin >> ctext;
	SubstringHash kira1(ctext, 1000003, 1000000007);
	SubstringHash kira2(ctext, 9999991, 1000000007);
	//cout << "kira's hashes computed" << endl;
	int m; cin >> m;
	vector<string> dict(m, "");
	unordered_map<ll, int> hashPlace;
	for (int i = 0; i < m; ++i) {
		cin >> dict[i];
		reverse(dict[i].begin(), dict[i].end());
		string toHash = tolower(dict[i]);
		hashPlace[(kira1(toHash) << 31) | kira2(toHash)] = i;
		//cout << "word " << i << " has hash combo " << ((kira1(toHash) << 31) | kira2(toHash)) << endl;
		reverse(dict[i].begin(), dict[i].end());
	}
	vector<bool> prefDoable(n + 1, false);
	vector<int> pred(n + 1, -1);
	vector<int> stringToPred(n + 1, -1);
	prefDoable[0] = true;
	for (int i = 1; i <= n; ++i) {
		int cHash1 = 0;
		int cHash2 = 0;
		for (int csb = i; csb > 0; --csb) {
			cHash1 = (cHash1 + (kira1.basePowers[i - csb] * ctext[csb-1])) % 1000000007;
			cHash2 = (cHash2 + (kira2.basePowers[i - csb] * ctext[csb-1])) % 1000000007;
			//cout << "hashes " << kira1.basePowers[i-csb] << " " << (int)ctext[csb-1] << endl;
			//cout << "substring from " << csb << " to " << i << " has hash combo " << ((cHash1 << 31) | cHash2) << endl;
			if (prefDoable[csb-1] && hashPlace.count((cHash1 << 31) | cHash2) > 0) {
				pred[i] = csb-1;
				stringToPred[i] = hashPlace[(cHash1 << 31) | cHash2];
				prefDoable[i] = true;
				//cout << csb << " to " << i << " is in set" << endl;
				break;
			}
		}
	}
	vector<int> wordsUsed;
	int cIdx = n;
	while (cIdx > 0) {
		wordsUsed.push_back(stringToPred[cIdx]);
		cIdx = pred[cIdx];
	}
	reverse(wordsUsed.begin(), wordsUsed.end());
	for (int wi : wordsUsed) {
		//cout << "(word " << wi << ")";
		cout << dict[wi] << " ";
	}
	cout << endl;
	return 0;
}