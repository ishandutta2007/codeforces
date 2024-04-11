#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int INF = 1e18;
const int MAXN = 1000;

int mul(int a, int b) {
	if (a > INF / b) return -1;
	return a * b;
}

bool check(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

void build() {
	int now = 1;
	vector<int> have;
	int cnt = 0;
	for (int i = 2; i < MAXN; i++) {
		if (!check(i)) continue;
		if (mul(now, i) != -1) {
			now = mul(now, i);
			have.push_back(i);
			cnt++;
			continue;
		}
		cout << "{";
		cout << now << ",";
		cout << "{";
		for (auto x : have) {
			cout << x;
			if (x != have.back()) cout << ",";
		}
		cout << "}}";
		cout << ",";
		cout << endl;
		now = i;
		have = {i};
	}
}

vector<pair<int, vector<int>>> have = {
{614889782588491410,{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}},
{38655288426304091,{53,59,61,67,71,73,79,83,89}},
{22125549654501673,{97,101,103,107,109,113,127,131}},
{316773187163046517,{137,139,149,151,157,163,167,173}},
{9879251463499721,{179,181,191,193,197,199,211}},
{39049078408188253,{223,227,229,233,239,241,251}},
{108538288030848139,{257,263,269,271,277,281,283}},
{309619196508457007,{293,307,311,313,317,331,337}},
{796229312542859009,{347,349,353,359,367,373,379}},
{4064625951224869,{383,389,397,401,409,419}},
{6860596063872959,{421,431,433,439,443,449}},
{10626236358872441,{457,461,463,467,479,487}},
{17092564102090369,{491,499,503,509,521,523}},
{30150641449095443,{541,547,557,563,569,571}},
{43889293834596251,{577,587,593,599,601,607}},
{60888412234461547,{613,617,619,631,641,643}},
{83850965748659689,{647,653,659,661,673,677}},
{122610116602749401,{683,691,701,709,719,727}},
{174123625045688707,{733,739,743,751,757,761}},
{244629182107482857,{769,773,787,797,809,811}},
{331523275336187063,{821,823,827,829,839,853}},
{433432014951605099,{857,859,863,877,881,883}},
{586300278030425213,{887,907,911,919,929,937}},
{779063344180506659,{941,947,953,967,971,977}}
};

int query(int x) {
	cout << "? " << x << endl;
	int ans;
	cin >> ans;
	return ans; 
}

void out_ans(int x) {
	cout << "! " << x << endl;
}

const int BUBEN = 13;
const int MXQ = 21;
mt19937 rnd(time(0));

int get(int p, int INF) {
	int ans = 1;
	while (ans * p < INF) {
		ans *= p;
	}
	return ans;
}

void solve() {
	vector<int> p;
	//int x = (rnd() % 10 == 0);
	int b = 4;
	for (int i = 0; i < b; i++) {
		int fans = query(have[i].first);
		for (auto x : have[i].second) {
			if (fans % x == 0) {
				p.push_back(x);
			}
		}
	}
	if (p.empty()) {
		out_ans(8);
		return;
	}
	int ans = 1;
	//shuffle(all(p), rnd);
	int now = 1;
	int INF = 1000000000;
	int can = MXQ - b;
	for (auto i : p) {
		if (can == 0) break;
		if (mul(now, get(i, INF)) != -1) {
			now *= get(i, INF);
			continue;
		}
		int fans = query(now);
		ans *= fans;
		INF /= fans;
		can--;
		now = get(i, INF);
	}
	if (now != 1 && can > 0) {
		ans *= query(now);
		can--;
	}
	int fout = 1;
	for (auto i : p) {
		int x = 1;
		while (ans % i == 0) {
			x++;
			ans /= i;
		}
		fout *= x;
	}
	while (can > 0) {
		int fans = query(have[b].first);
		for (auto x : have[b].second) {
			if (fans % x == 0) {
				fout *= 2;
			}
		}
		b++;
		can--;
	}
	out_ans(fout * 2);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}