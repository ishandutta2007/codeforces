//This just uses CHT and merge small to large
// Li Chao Segment Tree can also solve this (just do euler flatten i think)
#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long

const ll INF = 100000000000000LL; //its pretty big, i think

ll a[maxn];
ll b[maxn]; //these two are just the arrays as stated in the problem
int subsize[maxn]; //just compute subsize stuff
ll ans[maxn]; 		//store the answer for later printout
vector<vector<int>> adj(maxn);

//structs below to implement dynamic convex hull trick. i think this is quite nice
bool Q; //tells us whether we can just compare on last optimal x or not

struct Line {
	mutable ll k, m, p; //slope, y-intercep, last optimal x-value (thanks benq)
					    //mutable means we allow ourselves to be changed in by a const function
	bool operator<(const Line& o) const {
		if (Q) {
			return p < o.p; //if we compare on last x, do it
		}
		return k < o.k; //slope it up
	}
};

struct LineContainer : multiset<Line> { //Convex Hull Trick DS
	//store in a multiset
	ll div(ll v1, ll v2) { //the one in the editorial is confusing, so i looked at benq's
		//ok, this is just meant to do floor division but handle negatives correctly
		//v1 and v2 are used b/c i used a and b elsewhere

		if (v2 < 0) { //denominator is negative
			v1 *= -1;
			v2 *= -1; //we flip it b/c we do not want negative in denom
		}
		if (v1 >= 0) { //if the numerator is pos, then it is just like normal now
			return v1/v2;
		}
		//if numerator is negative, then we want the floor still
		// thus we find the one bigger in positive and then make it negative, giving floor
		return 0-((0-v1+v2-1LL)/v2);
	}
	bool isect(iterator x, iterator y) {
		//updates optimal spot for x
		//if y is useless we say it is
		if (y == end()) {
			//this means x is the last boy, so then it is useful for the rest of the time
			//also no need to delete the end iterator, that would be silly
			x->p = INF;
			return false;
		}
		if (x->k == y->k) {
			//same slope
			x->p = x->m > y-> m ? INF: -INF;
			//if greater y-intercept we are more useful
		}
		else {
			x->p = div(y->m - x->m, x->k - y->k);
			//last useful guy for x is then going to be when they cross (floor of it);
			//just set up simple equality for lines and this makes sense
		}
		return x->p >= y->p;
		//if i am useful past y and y is later than me, y is useless (get it out)

	}

	void add(ll k, ll m) { //add a new line with slope k and y-intercept m
		auto z = insert({k, m, 0}), y  = z++, x = y;
		//insert the thing with not really being useful and grab what is past it
		while (isect(y, z)) {
			z = erase(z); //while y overpowers z get z out of here
		}
		if (x != begin() && isect((--x), y)) {
			isect(x, y = erase(y)); 
			//if x is not the start grab what was before it and see if this overpowers 
			//		the next stuff
		}
		while ((y = x) != begin() && (--x)-> p >= y->p) {
			isect(x, erase(y)); //recalculate the needed values and do some stuff
			//erase y because it is useless
		}

	}
	ll query(ll x) {
		if (empty()) return 0LL; //this should not happen
		Q = true;
		auto l = *lower_bound({0,0,x}); //find what is best at this spot
		Q = false;
		return l.k * x + l.m; //just do the simple calculation
	}
};

void getsubsize(int u, int p) { //we do this so we merge from small to large
	subsize[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		getsubsize(v, u);
		subsize[u] += subsize[v];
	}
}

void dfs(int u, int p, LineContainer& cur) {
	//this is the main function we shall use
	//cur stores the state of the CHT
	int mx = -1; //max size of a subchild
	int bigChild = -1; //who is the biggest boy
	bool isleaf = true; //am i a leaf
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != p) { //am i the biggest boy?
			if (subsize[v] > mx) {
				mx = subsize[v];
				bigChild = v;
				isleaf = false;
			}
		}
	}
	if (bigChild != -1) {
		dfs(bigChild, u, cur); //establish the lincontainer as coming through this child
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != p && v != bigChild) {
			LineContainer tempo; //smaller line container / little guy
								 //this line container will be merged into the bigger boy
								//merge small to large is actually so cool. im freaking out
								//each child doubles it size each time. 
								//thus, it is merged at most lg n (WOW!)
			dfs(v, u, tempo);
			for (auto lcur : tempo) {
				cur.add(lcur.k, lcur.m);
			}

		}
	}
	if (!isleaf) {
		ans[u] = 0-cur.query(a[u]); //a matters for query
	}
	else { //im a leaf so i go in 0 time at all
		ans[u] = 0;

	}
	cur.add(0-b[u], 0-ans[u]); //b matters for insert
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	getsubsize(1, -1);
	LineContainer lc;
	dfs(1, -1, lc);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}
//REALLY NICE PROBLEM TO LOOK AT
//COVERS MERGE SMALL TO LARGE AND A NICE DYNAMIC CONVEX HULL TRICK IMPLEMENTATION