#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define pii pair<int, int>
#define tii tuple<int, int, int, int, int, int> 
//lol tuple of six things b/c why not
#define mp make_tuple 
//just some nice macros to make life easy

int n, q;
int a[maxn];
int atempo[maxn]; //just used for calculating prev vales
int upd[2][maxn]; //used for initial storage of updates

int prevtime, prevr, prevl; //stored so that we can keep up in addq and remq

vector<pii> ups; //store the updates here
vector<int> qprev; //store the value the update is replacing here
vector<tuple<int, int, int>> quers; //only three numbers needed for this tuple
map<int, int> compr; //compress value map
vector<int> vals; //the compressed numbers
int ans[maxn];	//answers - stored for later printing

int curin[maxn*2]; //just the current number seen for each val (2x because n+q)
int siz[maxn*2]; // how many values have this frequency rn

void addq(int spot) {
	if (spot == 0) return; //safety
	spot--; //zero indexed in the vector
	//add the update stored at index 'spot' in the ups array
	int prevval = qprev[spot]; 	 //the old value at the changing index
	int nval = ups[spot].second; //the new value in the array
	int ind = ups[spot].first;  //the index in the array that is changing
	a[ind] = nval; //so that 

	// cout << "changing  " << ind << "  from   " << prevval << " to " << nval << endl;
	
	if (ind >= prevl && ind <= prevr) { //actually affects current state
		curin[prevval]--; //simply change the two arrays for new indices
		siz[curin[prevval]+1]--;
		siz[curin[prevval]]++;
		
		curin[nval]++;
		siz[curin[nval]]++;
		siz[curin[nval]-1]--;
	}

	
}

void remq(int spot) {
	if (spot == 0) return; //safety
	//remove the update at index 'spot'
	spot--; //zero indexed in vector
	int prevval = qprev[spot]; 	 //the old value at the changing index
	int nval = ups[spot].second; //the new value in the array
	int ind = ups[spot].first;  //the index in the array that is changing
	a[ind] = prevval; //errr... undo the thing i think
	
	// cout << "(un)changing  " << ind << "  from   " << nval << " to " << prevval << endl;

	if (ind >= prevl && ind <= prevr) { //make sure it actually matters
		curin[prevval]++;   //simply change the two arrays for new indices, 
						// (backwards of insert)
		siz[curin[prevval]-1]--;
		siz[curin[prevval]]++;
		
		curin[nval]--;
		siz[curin[nval]]++;
		siz[curin[nval]+1]--;
	}

	

}

void addv(int spot) {
	if (spot == 0) return; //happens in first case
	//add the value at spot index
	curin[a[spot]]++;
	siz[curin[a[spot]]-1]--;
	siz[curin[a[spot]]]++;

}
void remv(int spot) {
	if (spot == 0) return; //happens in first case
	//remove the value at 'spot' index
	//remove is just backwards of add (once again)
	curin[a[spot]]--;
	siz[curin[a[spot]]+1]--;
	siz[curin[a[spot]]]++;

}

int calcans() {
	//just uses the arrays that are maintained through the mo's alg
	for (int i = 1; i < maxn; i++) {
		assert(siz[i] >= 0 && "Size must be non-negative"); //this is failing rn
		if (siz[i] == 0) return i;
		//guaranteed to return in 2 sqrt n time, but we loop for a while anyway
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> q;
	set<int> seen; //set of numbers seen
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		seen.insert(a[i]);
	}
	int oc = 0; //one type queris seen
	int tc = 0; //two type queries seen
	int tp;
	int l, r, p, x, t, ind; 
	// t will be as in editorial, the number of updates before me
	// ind will just be used to index the queries to re-print answers at the end
	for (int i = 0; i < q; i++) {
		cin >> tp;
		if (tp == 1) {
			oc++;
			cin >> l >> r;
			quers.push_back(mp(l, r, tc));
		}
		else {
			tc++;
			cin >> p >> x;
			seen.insert(x); //for compression later
			upd[0][tc] = p; //just store b/c why not
			upd[1][tc] = x; //idk why i indexed in this order
		}
	}
	for (auto it = seen.begin(); it != seen.end(); ++it) {
		vals.push_back(*it);
	}
	for (int i = 0; i < vals.size(); i++) {
		compr[vals[i]] = i;
	}

	//must update initial values and update values to be compressed
	for (int i = 1; i <= n; i++) {
		a[i] = compr[a[i]]; //map to compress stuff
		atempo[i] = a[i]; //initalize to same
	}
	for (int i = 1; i <= tc; i++) {
		p = upd[0][i];
		x = compr[upd[1][i]];
		ups.push_back(pii(p, x));
		qprev.push_back(atempo[p]); //value i am replacing
		atempo[p] = x;				//assing new value to tempo guy
	}

	vector<tii> mods; //modified queries so that we can process them
	int pb = cbrt(max(n, q))*cbrt(max(n, q)); //get the desired bucketing scheme
	for (int i = 0; i < quers.size(); i++) {
		l = get<0>(quers[i]);
		r = get<1>(quers[i]);
		t = get<2>(quers[i]);
		int buck1 = t/pb; //divide to bucket stuff
		int buck2 = l/pb;
		mods.push_back(mp(buck1, buck2, r, l, t, i));
	}
	sort(mods.begin(), mods.end()); //sort to do mo's algorithm

	prevtime = 0;
	prevr = 0;
	prevl = 0;
	//these previous values should do the trick

	fill(curin, curin+2*maxn, 0); //initialize the two arrays
	fill(siz, siz+maxn, 0);

	for (int i = 0; i < mods.size(); i++) {
		r = get<2>(mods[i]);
		l = get<3>(mods[i]);
		t = get<4>(mods[i]);
		ind = get<5>(mods[i]);
		// cout << "processing  " << r << " " << l << " " << t << " " << ind << endl;
		//no need to recover buckets because they are just used for sorting

		//update time change first b/c it could come into play while shifting
		//		errr... i guess it should not matter

		while (prevtime < t) {
			prevtime++;
			addq(prevtime);
		}
		while (prevtime > t) {
			remq(prevtime);
			prevtime--;
		}

		//below just does the shifting based on r and l
		while (prevr < r) {
			prevr++;
			addv(prevr);
		}
		while (prevl > l) {
			prevl--;
			addv(prevl);
		}
		while (prevr > r) {
			remv(prevr);
			prevr--;
		}
		while (prevl < l) {
			remv(prevl);
			prevl++;
		}

		ans[ind] = calcans(); //store the current answer (not even bottleneck)
	}


	//here we print answers
	for (int i = 0; i < oc; i++) { //i think this indexing is right
		cout << ans[i] << endl;
	}
	cin >> n; //just for ease of viewing solution
}

//MAKE SURE YOU ARE ADDDING AND REMOVING CORRECTLY
//OVERLAPPING THE RANGES IS BAD ( ;( )
//THERE IS SOME STUPID BUG ARGGG