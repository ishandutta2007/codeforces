#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define pii pair<int, int>

int n, k; //globals boys
int u;
vector<vector<pii>> adj(maxn); //use edge id i guess
int a[maxn]; //time used to create the ith thing
// vector<map<int, pii>> dp(maxn); //sort of is a dp
//Could probably transition map into indexed array but sounds exhausting

// //not sure if i still need the two guys below me
// int dpf[maxn*2]; //double the edge size
// int dps[maxn*2]; //the second value in the dp

//the pair of my edge is my edge ^ 1 (yay for fun tricks)
int state[maxn]; //0 means nothing at all, 1 means 1 guy left, 2 means completely done
int lastproc[maxn]; //edge id for last edge i have to process
int freesum[maxn]; //sum of the free guys from me
int edgeend[maxn*2]; //end of the edge for this edge id
int maxfinal[2][maxn]; //store both of the final best guys for me (index 0 is the better one)
int maxfinalid[2][maxn]; //store the ids of the best guys for me 
int bad[maxn]; //for pre-dfs stuff
int good[maxn]; //anti-bad
int par[maxn]; 
int root[maxn]; //root of pre-dfs

void addinfo(int v, int r, int lid) { //make sure ordering of variables is consisten
	//add the stuff from v to r
	//lid is the id of the edge linking r to v
	//this will only be called if all necessary stuff has happened 
	//maybe we should add an edge id just in case
	//handle case where v is illegal separately
	if (a[v] < u) { //v is illegal
		if (0 > maxfinal[0][r]) {
			maxfinal[0][r] = 0;
			maxfinalid[0][r] = v; //no need to shift over because this implies 2 -1
		}
		else if (0 > maxfinal[1][r]) {
			maxfinal[1][r] = 0;
			maxfinalid[1][r] = v;
		}
		return; //easy to handle special case i think
	}
	
	
	//now we know that v will be legal
	if (state[v] == 2) { //interestingly we know that r has already fed into v 
		//imagine it as a forest, everything goes down on initial rooting 
		//thus if we are already done then our parent has fed into us before (i think)
		//values for v contain values for r already
		bool risfree = false;
		if (par[v] == r) {
			risfree = bad[root[r]] == bad[v];
		}
		else {
			risfree = bad[r] == 0;
		}
		int cans = freesum[v];
		// cout << "original freesum was  " << freesum[v] << endl;
		bool visfree = true;
		if (maxfinalid[0][v] == r) {
			if (maxfinal[1][v] != -1) {
				visfree = false;
				cans += maxfinal[1][v];
			}

		}
		else {
			 if (maxfinal[0][v] != -1) {
			 	visfree = false;
			 	cans += maxfinal[0][v];
			 }
		}
		if (risfree) {
			if (par[r] == v) {
				cans -= good[r];
			}
			else cans -= good[root[r]] - good[v];
		}
		if (visfree) {
			freesum[r] += cans;
		}
		else {
			if (cans > maxfinal[0][r]) {
				maxfinal[1][r] = maxfinal[0][r];
				maxfinalid[1][r] = maxfinalid[0][r];
				maxfinal[0][r] = cans;
				maxfinalid[0][r] = v;
			}
			else if (cans > maxfinal[1][r]) {
				maxfinal[1][r] = cans;
				maxfinalid[1][r] = v;
			}
		}

	}
	else { //state v is 1 and we know that the last thing to process is the edge from r to v
		// cout << "asserting for  " << v << endl;
		assert(state[v] == 1); //i am pretty sure the state should always be 1
		int cans = freesum[v];
		int cadd = maxfinal[0][v] == -1 ? 0 : maxfinal[0][v];
		cans += cadd;
	
		if (maxfinal[0][v] == -1) {
			freesum[r] += cans;
		}
		else {
			if (cans > maxfinal[0][r]) {
			
				maxfinal[1][r] = maxfinal[0][r]; //these two lines just shift floating max
				maxfinalid[1][r] = maxfinalid[0][r];
				maxfinal[0][r] = cans; //replace best guy
				maxfinalid[0][r] = v;
			}
			else if (cans > maxfinal[1][r]) {
				maxfinal[1][r] = cans;
				maxfinalid[1][r] = v;
			}
		}

	}
	
}

void recur(int v, int pid) { //process v as if it is coming from edge pid
	// cout << "recurring  for   " << v << endl;
	if (a[v] < u) return; //no need to process me because i stink

	if (state[v] == 2) {
		return; //already processed everything
	}
	if (state[v] == 1) { //can only ever be processed once like this
		if ((pid ^ 1) == lastproc[v]) { //the last edge to process is where i come from
			//get the flip of the edge using xor (yay fun trick)
			return;
		}
		int nx = lastproc[v]; //process this edge now
		recur(edgeend[nx], nx); //go to the edge end through the edge
		addinfo(edgeend[nx], v, nx);
		state[v] = 2; //completely done now 
		return; //add the info
	}
	if (state[v] == 0) { //happens once for every node
		for (auto nx : adj[v]) {
			if (nx.second == (pid ^ 1)) continue; //do not process
			recur(nx.first, nx.second);
			addinfo(nx.first, v, nx.second); // classical addition of information
		}
		state[v] = 1; //now we are almost done
		lastproc[v] = pid ^ 1; //last guy left
	}
}

int getans(int r) {

	if (a[r] < u) { //not allowed to use it
		return 0; //get this out. we hate it
	}
	
	if (state[r] == 1) { //only one left
		int nval = lastproc[r];
		recur(edgeend[nval], nval);
		addinfo(edgeend[nval], r, nval);
	}
	else if (state[r] == 0) { //miles to go before we sleep
		for (auto v : adj[r]) {
			recur(v.first, v.second);
			addinfo(v.first, r, v.second);
		}
	}
	state[r] = 2; //guaranteed we have processed everything
	
	int mf = maxfinal[0][r] == -1 ? 0 : maxfinal[0][r]; //mf is just like max final but fixed
	// cout << "     freesum  for  " << r << "  is   " << freesum[r] << endl;
	// cout << "---->answer for  " << r << " is  " << freesum[r] + mf << 
	// 	"  with freesum  " << freesum[r] <<  "  and mf " << mf <<
	// 	" from id  " << maxfinalid[0][r] <<  endl;
	return freesum[r] + mf; //yay good to go
}

void predfs(int v) {
	good[v] = 1; //i know i am good myself
	if (par[v] == -1) {
		root[v] = v;
	}
	bad[v] = 0;
	for (auto x : adj[v]) {
		if (x.first == par[v]) continue; //no infinite loop allowed
		if (a[x.first] < u) {
			bad[v]++;
			continue;
		}
		root[x.first] = root[v]; //we are in the same tree how fun
		par[x.first] = v;
		predfs(x.first);
		bad[v] += bad[x.first];
		good[v] += good[x.first];
	}
}

bool check() { //keep u outside so that we can basically have it for all functions
	int best = 0; //best must be greater than or equal to k to win this boy
	// cout << endl <<  "checking   " << u << endl;
	// fill(dpf, dpf+maxn*2, -1); //-1 means not processed here
	fill(state, state+maxn, 0); //fills could be transferred into predfs if needed
	fill(maxfinal[0], maxfinal[0]+maxn, -1);
	fill(maxfinal[1], maxfinal[1]+maxn, -1);
	fill(maxfinalid[0], maxfinalid[0]+maxn, -1); //this and one below should not be needed
	fill(maxfinalid[1], maxfinalid[1]+maxn, -1);
	fill(freesum, freesum+maxn, 1); //need to consider everyone gets one themselves for free? 
	fill(par, par+maxn, -1); //-1 signifies no parent
	//fill should be fast enough i think 
	for (int i = 1; i <= n; i++) {
		if (a[i] >= u && par[i] == -1) predfs(i); //do for all roots of represented trees
	}

	for (int i = 1; i <= n; i++) {
		// cout << "process  " << i << endl;
		best = max(best, getans(i)); //consider i to be the root
		// cout << "done processing" << endl;
		//special cases will be handled in getans and its children functions
	}
	// cout << "u   " << u << " gives:  " << best << endl;
	return best >= k; //this is what we want
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("output.txt", "w", stdout); //just for local debugging
	cin >> n >> k;
	int u1, v; //changed to u1 b/c i used u elsewhere (oops)
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cid = -1; //make sure xor works properly (early increment or smth)
	for (int i = 0; i < n-1; i++) {
		cin >> u1 >> v;
		cid++;
		adj[u1].push_back({v, cid});
		edgeend[cid] = v;
		cid++;
		adj[v].push_back({u1, cid});
		edgeend[cid] = u1;
	}
	// cout << "here   " << endl;
	int lo = 1;
	int hi = 1000000; //max and min values for a
	while (lo < hi) { //binary search should still be ok
		int mid = (lo+hi+1)/2;
		u = mid; //assign the global boy
		if (check()) { //if we can do it with greater than or equal to this
			lo = mid;
		}
		else {
			hi = mid-1;
		}
	}
	cout << lo << endl;
	cin >> n;
}
//why is the time limit so high?
//hopefully the map is ok
//maybe constant factor is garb
//make sure u, r, v are all used correctly (kind of not consistent with normal)
//new goal: figure out how to not be bad at analysis and code o(n^2)