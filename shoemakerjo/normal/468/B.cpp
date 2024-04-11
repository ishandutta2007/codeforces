#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

set<int> nums;
set<int> A;
set<int> B;
int n, a, b;
bool isvalid;

int on[maxn]; //original numbers

void insA(int x) {

	if (nums.find(x) == nums.end()) {
		isvalid = false;
		return;
	}
	nums.erase(x);
	A.insert(x);
	if (a - x != x) {
		if (nums.find(a-x) == nums.end()) { //this would mean we're done
			isvalid = false;
			return;
		}
		nums.erase(a-x);
		A.insert(a-x);
		
	}
	int tmp = b - x;
	if (A.find(tmp) != A.end() && nums.find(tmp) != nums.end()) {
		insA(tmp);
	}
	assert(B.find(tmp) == B.end());
	tmp = b - (a-x);
	if (A.find(tmp) == A.end() && nums.find(tmp) != nums.end()) {
		insA(tmp);
	}
	// assert(B.find(tmp) == B.end());

	// assert(A.find(a-x) == A.end());
}

void insB(int x) {
	//whenever i am inserted to B, my friend should be checked
	if (nums.find(x) == nums.end()) {
		isvalid = false;
		return;
	}
	nums.erase(x);
	B.insert(x);
	if (b - x != x) { //if it is added we just added it
		if (nums.find(b-x) == nums.end()) {
			isvalid = false;
			return;
		}
		nums.erase(b-x);
		B.insert(b-x);
		
	}
	// cout << "inserted " << b << " " << b-x << endl;
	int tmp = a - x;
	if (B.find(tmp) != B.end() && nums.find(tmp) != nums.end()) {
		//this can't be in A anymore b/c its partner is gone
		insB(tmp);
	}
	assert(A.find(tmp) == A.end());

	tmp = a - (b-x);
	if (B.find(tmp) == B.end() && nums.find(tmp) != nums.end()) {
		insB(tmp);
	}

	// cout << "two tmps: " << a-x << " " << tmp << endl;
	// assert(A.find(tmp) == A.end());
	// assert(B.find(b-x) != B.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> on[i];
		nums.insert(on[i]);
	}
	isvalid = true; //mark this if not
	for (int i = 0; i < n; i++) {
		if (nums.find(on[i]) == nums.end()) continue; //already removed
		if (nums.find(a-on[i]) == nums.end()) {
			insB(on[i]);
		}
		else if (nums.find(b-on[i]) == nums.end()) {
			insA(on[i]);
		}
		// cout << "can be in either: " << on[i] << endl;
		//else means this guy could go in either set
	}
	//the top is supposed to be stable (oops)
	for (int i = 0; i < n; i++) {
		//if we are still around, put us wherever
		if (nums.find(on[i]) != nums.end()) {
			// assert(A.find(on[i]) == A.end() && B.find(on[i]) == B.end());
			//could make this insA if we feel it is needed
			A.insert(on[i]);
			// bool ok = A.find(a-on[i]) != A.end() || 
			// 	nums.find(a-on[i]) != nums.end();
			// if (!ok) {
			// 	cout << "This fails: " << on[i] << " " << a-on[i] << endl;
			// }
		}
	}

	if (!isvalid) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (A.find(on[i]) != A.end()) {
				cout << 0 << " ";
				// assert(A.find(a-on[i]) != A.end());
			}
			else {
				assert(B.find(on[i]) != B.end());
				assert(B.find(b-on[i]) != B.end());
				cout << 1 << " ";
			}

		}
		cout << endl;
	}
	cin >> n;

}
//asserts are not failing until we get to the print stage(i don't understand)