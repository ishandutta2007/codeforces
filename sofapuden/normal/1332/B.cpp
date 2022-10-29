#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;


void solve() {
	set<int> primeuse;
	int n;
	cin >> n;
	vector <vector<int>> q(11);
	vector<int> seq;
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		if (tmp % 2 == 0) {
			primeuse.insert(2);
			q[0].push_back(tmp);
			seq.push_back(0);
		}
		else if (tmp % 3 == 0) {
			primeuse.insert(3);
			q[1].push_back(tmp);
			seq.push_back(1);
		}
		else if (tmp % 5 == 0) {
			primeuse.insert(5);
			q[2].push_back(tmp);
			seq.push_back(2);
		}
		else if (tmp % 7 == 0) {
			primeuse.insert(7);
			q[3].push_back(tmp);
			seq.push_back(3);
		}
		else if (tmp % 11 == 0) {
			primeuse.insert(11);
			q[4].push_back(tmp);
			seq.push_back(4);
		}
		else if (tmp % 13 == 0) {
			primeuse.insert(13);
			q[5].push_back(tmp);
			seq.push_back(5);
		}
		else if (tmp % 17 == 0) {
			primeuse.insert(17);
			q[6].push_back(tmp);
			seq.push_back(6);
		}
		else if (tmp % 19 == 0) {
			primeuse.insert(19);
			q[7].push_back(tmp);
			seq.push_back(7);
		}
		else if (tmp % 23 == 0) {
			primeuse.insert(23);
			q[8].push_back(tmp);
			seq.push_back(8);
		}
		else if (tmp % 29 == 0) {
			primeuse.insert(29);
			q[9].push_back(tmp);
			seq.push_back(9);
		}
		else if (tmp % 31 == 0) {
			primeuse.insert(31);
			q[10].push_back(tmp);
			seq.push_back(10);
		}
	}
	int counter = 1;
	int arr[11];
	rep(i, 0, 11) {
		if (!q[i].empty()) {
			arr[i] = counter;
			counter++;
		}
	}

	cout << primeuse.size() << "\n";

	rep(i, 0, seq.size()) {
		cout << arr[seq[i]] << " ";
	}
	cout << "\n";
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}