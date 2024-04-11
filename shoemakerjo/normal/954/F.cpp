#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>

const int mod = 1000000007;

int n;
ll m;

void add(int &a, int b) {
	a = (a+b)%mod;
}

int mult(int a, int b) {
	return (a*1LL*b)%mod;
}

struct Matrix {
	int mat[3][3]; //this is standard
};

struct interval {
	bool block[3];
	ll l, r; //must be longs


	bool operator < (const interval& rhs)  const { //really did not need this sort
		if (l != rhs.l) {
			return l < rhs.l;
		}
		return r <  rhs.r;
	}
};

Matrix matMult(Matrix a, Matrix b) {
	Matrix ans;
	//only need naive matrix exponentiation here
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ans.mat[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				add(ans.mat[i][j], 
					mult(a.mat[i][k], b.mat[k][j]));
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) ans.mat[i][j] = 1;
			else ans.mat[i][j] = 0;
		}
	} //this constructs the identity matrix we need
	while (p) {
		if (p & 1) {
			ans = matMult(ans, base);
		}
		base = matMult(base, base);
		p = p/2;
	}
	return ans;
}

void printmat(Matrix cur) { //soley for debugging purposes
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cur.mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; //make it look nicer
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m; 
	//separating out ranges should not be too bad	
	//	ranges will be bulk of nasty code though
	//	start at 1 and have it such that this is 0 1 0
	//constantly do transforms to the 0 1 0 and see result
	Matrix fin; //this should be final matrix
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fin.mat[i][j] = 0;
		}
		fin.mat[i][i] = 1; //only contribute once
	}

	int a;
	ll l, r;
	//annoying part is doing all this stuff with the things
	vector<interval> vi; //have to made a decision w/this
	set<ll> bounds;
	while (n--) { //can probably do it with n^2 cancelling
		cin >> a >> l >> r;
		bounds.insert(l);
		bounds.insert(r+1LL); //might be better like this
						  //consider changing to r+1
		interval cur;
		cur.l = l;
		cur.r = r+1LL; //i think this is right
		for (int i = 0; i < 3; i++) cur.block[i] = false; 
		//we could just store like this and 
		//	then convert to more complex
		cur.block[a-1] = true; //-1 to allow zero indexing
		vi.push_back(cur);
	}
	// sort(vi.begin(), vi.end()); //could take this out if needed
	vector<ll> spots;
	bounds.insert(m); //add the final guy (exclusive?)
	//try not m+1 and do inclusive shifting
	bounds.insert(1LL); //think we want to do this 
	for (auto v : bounds) {
		spots.push_back(v);
	}
	vector<interval> finnt; //final interval set
	for (int i = 0; i < spots.size()-1; i++) { //will only be o(n) of these
		interval nc;
		nc.l = spots[i];
		nc.r = spots[i+1];
		for (int j = 0; j < 3; j++) nc.block[j] = false;
		finnt.push_back(nc); //just somewhat of a generic thing
	}
	for (int i = 0; i < vi.size(); i++) {
		//i affect all intervals that go from my start to my end
		int st = lower_bound(spots.begin(), spots.end(), vi[i].l)-spots.begin();
		int en = lower_bound(spots.begin(), spots.end(),  vi[i].r)-spots.begin(); //could change
		for (int j = st; j < en; j++) { //check the equality here
			assert(j < spots.size());
			for (int k = 0; k < 3; k++) {
				finnt[j].block[k] |= vi[i].block[k]; //or equal here
			}
		}
	}

	// cout << "original fin" << endl;
	// printmat(fin);

	//here we hope that we have done everything
	//exclusive versus inclusive
	for (int i = 0; i < finnt.size(); i++) {
		interval tempo = finnt[i];
		Matrix nx; //gets standardized below
		nx.mat[0][0] = 1; //0 contributes 1 to 0
		nx.mat[0][1] = 1; //1 contribtues 1 to 0
		nx.mat[0][2] = 0;
		nx.mat[1][0] = 1;
		nx.mat[1][1] = 1;
		nx.mat[1][2] = 1;
		nx.mat[2][0] = 0;
		nx.mat[2][1] = 1;
		nx.mat[2][2] = 1; 
		// cout << "nx   " << endl;
		// printmat(nx);
		//above should set everything properly
		for (int j = 0; j < 3; j++) {
			if (tempo.block[j]) { //no go here
				for (int k = 0; k < 3; k++) {
					// nx.mat[k][j] = nx.mat[j][k] = 0; //no contribution to or from me
					nx.mat[j][k] = 0; //i cannot contribute (but why not go to me anyway)
				}
			}
		}
		// cout << "processing  " << tempo.l << "  " << tempo.r << endl;
		// cout << "nx value" << endl;
		// printmat(nx);

		nx = matPow(nx, tempo.r-tempo.l); //be careful of bounds here
		fin = matMult(fin, nx); //multiply these two
		// fin = matMult(nx, fin);
		//  if bad, flip the order of multiplication

		// printmat(fin);
	}
	// printmat(fin);
	cout << fin.mat[1][1] << endl; //contributes to 1 by 1. 
	//		all else is 0 so who cares
	cin >> n;

}
//getting 2x the correct answer for some reason, probably a bounds thing i'm guessing
//probably not overflow b/c of the 2x thing