#include <bits/stdc++.h>

using namespace std;



struct trie {
	int siz;
	trie *one;
	trie *zero;
	bool isbase;
	trie() :
		one(NULL), zero(NULL), siz(0)
	 {
	 	isbase = false;
	 }

	void update() {
		siz = 0;
		if (isbase) {
			siz = 1;
			return;
		}
		if (one) siz += one->siz;
		if (zero) siz += zero->siz;
	}


};



vector<int> bin;
trie *root;


void insert() {
	//use the bin vector
	trie *cur = root;
	for (int i = 0; i < 30; i++) {
		cur->siz = cur->siz+1;
		if (bin[i] == 1) {
			if (cur->one != NULL) {
				cur = cur->one;
			}
			else {
				trie *tp = new trie();
				cur -> one = tp;
				cur = tp;
			}
		}
		else {
			if (cur->zero != NULL) {

				cur = cur->zero;

			}
			else {
				trie *tp = new trie();
				cur->zero = tp;
				cur = tp;
				// cur = new trie();
			}
		}
	}
	// if (!cur->isbase) {
	// 	cur->isbase = true;
		
	// }
	cur->siz++;
}

int query() {
	// cout << "sz   " << bin.size() << endl;
	trie *cur = root;
	int ans = 0;
	// vector<int> reco;
	for (int i = 0; i < 30; i++) {
		// cout << "		 " << i << " " << bin[i] <<  "    " << cur->siz << endl;
		if (bin[i] == 0) {
			if (cur->zero != NULL && cur->zero->siz > 0) {
				cur = cur->zero;
				// cout << "WENT ZERO" << endl;
				// reco.push_back(0);
				ans =ans*2;
			}
			else {
				cur = cur->one;
				// cout << "WENT ONE BAD" << endl;
				// reco.push_back(1);
				ans = ans*2+1;
			}
		}
		else {
			if (cur->one != NULL && cur->one->siz > 0) {
				cur = cur->one;
				// cout << "WENT ONE" << endl;
				// reco.push_back(1);
				ans = ans*2+1;
			}
			else {
				// cout << "WENT ZERO BAD" << endl;
				cur = cur->zero;
				// reco.push_back(0);;
				ans = ans*2;
			}
		}
	}
	// cout << " ans   " << ans << endl;
	return ans;

}

void remo() {
	//remove what is stored in bin
	trie *cur = root;
	for (int i = 0; i < 30; i++) {
		cur->siz --;
		if (bin[i] == 0) {
			cur = cur->zero;
		}
		else cur = cur->one;
	}
	cur->siz--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int A[N];
	int P[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	root = new trie();
	for (int i = 0; i < N; i++) {
		int cur = P[i];
		bin.clear();
		for (int j = 0; j < 30; j++) {
			if (cur & 1) {
				bin.push_back(1);
			}
			else bin.push_back(0);
			cur /= 2;
		}
		reverse(bin.begin(), bin.end());
		insert();

	}
	// cout << "here  " << root->siz << endl;
	for (int i = 0; i < N; i++) {
		int cur = A[i];
		bin.clear();
		for (int j = 0; j < 30; j++) {
			if (cur & 1) {
				bin.push_back(1);
			}
			else bin.push_back(0);
			cur /= 2;
		}
		reverse(bin.begin(), bin.end());
		int tempo = query();
		cout << (A[i] ^ tempo) << " ";
		//above is answer printout
		cur = tempo;
		bin.clear();
		for (int j = 0; j < 30; j++) {
			if (cur & 1) {
				bin.push_back(1);
			}
			else bin.push_back(0);
			cur /= 2;
		}
		reverse(bin.begin(), bin.end());
		remo();
		
	}
	cout << endl;
	cin >> N;

	
}