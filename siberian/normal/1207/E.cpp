#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = (1 << 14);
set<int> xors;
	
bool check(int x) {
	for (int i = 0; i < 100; i++) {
		if (xors.count(x ^ i))
			return false;
	} 
	return true;
}


void gen() {
	vector<int> a;
	for (int i = 0; i < 100; i++)
		a.push_back(i);
	vector<int> b;
	for (int i = 0; i < 100; i++) {
		int x;
		x =	abs(rand()) % MAXN;
		while (!check(x)) {
			x =	abs(rand()) % MAXN;
		}
		b.push_back(x);
		for (int i = 0; i < 100; i++)
			xors.insert(i ^ x);
	}
	for (auto i : a)
		cout << i << ",";
	cout << endl;
	for (auto i : b)
		cout << i << ",";
	cout << endl;
}

vector<int> a = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
vector<int> b = {1383,9158,6249,2163,7249,7423,5194,6380,7977,15565,6059,498,7931,10723,8518,124,8898,10232,8987,3559,909,3958,9562,14638,12899,563,1225,1946,15206,7474,4109,14897,9304,12451,6490,2397,12549,10328,6889,1118,10452,15787,3250,4301,8390,13979,1553,7554,14452,13601,15677,6768,5281,14561,11772,10903,14826,2780,4971,14230,3626,748,1787,3388,2540,6936,16347,251,9978,826,1531,12293,316,14204,4056,5566,12124,13839,13803,9457,15877,3063,16128,1892,5821,4639,11899,11028,2577,4361,6620,7124,4594,7707,3811,5704,9717,11290,13476,10062};


void solve() {
	cout << "? ";
	for (auto i : a)
		cout << i << " ";
	cout << endl;
	int x1;
	cin >> x1;
	cout << "? ";
	for (auto i : b)
		cout << i << " ";
	cout << endl;
	int x2;
	cin >> x2;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if ((a[i] ^ b[j]) == (x1 ^ x2)) {
				cout << "! " << (a[i] ^ x1) << endl;
				return;
			}
		}
	}
	assert(false);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}