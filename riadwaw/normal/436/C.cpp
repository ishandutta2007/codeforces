//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock(); 
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0); 
    cout.precision(10);
    cout << fixed;
    int t = 1;
   //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}


void solve() {
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<string> s(k);
	for(int j = 0; j < k; ++j)
		for(int i = 0; i < n; ++i) {
			string t;
			cin >> t;
			s[j] += t;
		}
	
	n = n * m;
	vector<pi> ans;
	ans.reserve(k);
	
	
	vector<vi>  dist(k, vi(k));
	
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < i; ++j) {
			int diff = 0;
			for(int l = 0; l < n; ++l) {
				if(s[i][l] != s[j][l]) {
					++diff;
				}
				
			}
			
			
			
			dist[i][j] = dist[j][i] = diff * w;
		}
	}
	
	vector<int> used(k);
	vector<int> curDist(k, n);
	
	
	li res = 0 ;
	for(int it = 0; it < k; ++it) {
		int best = -1;
		for(int i = 0; i < k; ++i) {
			if(used[i])continue;
			if(best == -1 || curDist[i] < curDist[best]) {
				best = i;
			}
		}
		assert(best != -1);
		res += curDist[best];
		if(curDist[best] == n) {
			ans.push_back(mp(best + 1, 0));
		}
		else {
			int nei = -1;
			for(int i = 0; i < k; ++i) {
				if(used[i] && dist[i][best] == curDist[best]) {
					nei = i;
					break;
				}
			}
			assert(nei != -1);
			ans.push_back(mp(best + 1, nei + 1));
		}
		used[best] = true;
		for(int i = 0; i < k; ++i) {
			curDist[i] = min(curDist[i], dist[i][best]);
		}
		
		
	}
	
	cout << res << "\n";
	for(int i = 0; i < k; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << "\n";
	}
}