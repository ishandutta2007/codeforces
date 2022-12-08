#include <bits/stdc++.h>

using namespace std;
#define ll long long
//need lls because annoying input and summing can get out of hand
#define maxn 400010
// #define endl '\n'

const ll INF = 10000000000000000LL; //bigger than any value for X 

ll psum[20][maxn]; //first set of binary lifting strategy
int parsum[20][maxn]; //also store the parent for the sequencing

int par[20][maxn]; //just fill par with the next guy (actual parent)
ll mw[20][maxn]; //max weight on this binary lifting path

ll weights[maxn]; //just store the weights, needed for first step of query

void ins(int ct, int R, ll W) {
	par[0][ct] = R;
	for (int i = 1; i <= 19; i++) { //construct direct parent stuff easily
		if (par[i-1][ct] != -1) {
			par[i][ct] = par[i-1][par[i-1][ct]];
		}
		else par[i][ct] = -1;
	}
	mw[0][ct] = weights[R];
	for (int i = 1; i <= 19; i++) {
		if (par[i][ct] == -1) {
			mw[i][ct] = INF;
		}
		else {
			mw[i][ct] = max(mw[i-1][ct], mw[i-1][par[i-1][ct]]); //i think this is ok
		}
	}

	weights[ct] = W;
	
	int cur = R;  
	int nx;
	if (weights[cur] < W) {
		for (int i = 19; i >= 0; i--) {
			if (mw[i][cur] < W) {
				cur = par[i][cur];
			}
		}
		nx = par[0][cur];
	}
	else {
		nx = R;
	}
	// cout << "nx  for  " << ct << "  is   " << nx << endl;
	//nx now stores the parent in the sequence
	parsum[0][ct] = nx; //link to direct parent
	psum[0][ct] = nx == -1 ? INF : weights[nx];

	for (int i = 1; i <= 19; i++) {
		if (parsum[i-1][ct] != -1) {
			parsum[i][ct] = parsum[i-1][parsum[i-1][ct]];
		}
		else parsum[i][ct] = -1;
		if (parsum[i][ct] == -1) {
			psum[i][ct] = INF;
		}
		else {
			psum[i][ct] = psum[i-1][ct] + psum[i-1][parsum[i-1][ct]];
		}
	}
}

int query(int R, ll X) {
	if (weights[R] > X) return 0;
	int ans = 1;
	X -= weights[R];
	for (int i = 19; i >= 0; i--) {
		if (psum[i][R] <= X) {
			ans += (1 << i);
			X -= psum[i][R];
			R = parsum[i][R];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Q;
	cin >> Q;
	int tp; //type of query
	ll p, q; //vals for query
	ll last = 0LL; //use to decode queries
	int R; //this is always in a reasonable range (int needed for indexing)
	ll W, X; 
	int ct = 1; //node identifiers
	for (int i = 0; i < 20; i++) { 
		fill(psum[i], psum[i]+maxn, INF); //make sure this will all blow up
		fill(parsum[i], parsum[i]+maxn, -1);
		fill(par[i], par[i]+maxn, -1); //-1 signifies no proper parent
		fill(mw[i], mw[i]+maxn, -1);
	}
	while (Q--) { //process the queries
		cin >> tp >> p >> q; //always same read-in style
		if (tp == 1) { //insertion query
			R = p ^ last;
			W = q ^ last;
			ct++;
			ins(ct, R, W);
		}
		else { //get path length query
			R = p ^ last;
			X = q ^ last;
			// cout << "ANS:   "; //just make printing easier for now
			last = query(R, X);
			cout << last << endl;
		}
	}
	cin >> Q;

}