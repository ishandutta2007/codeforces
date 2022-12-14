// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 0, mod = (int) 0;
const int maxn = 1e5 + 10;
int cnt[maxn], a[maxn], b[maxn];
vector<int> x[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];	
		a[i]--;
		cnt[a[i]]++;
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
		x[a[i]].push_back(b[i]);
	}
	multiset<int> s;
	for(int i=0; i<k; i++){
		if(cnt[i]){
			sort(ALL(x[i]));
			for(int j=0; j+1<x[i].size(); j++)
				s.insert(x[i][j]);		
		}
	}	
	long long ans = 0;
	for(int i=0; i<k; i++){
		if(!cnt[i]){
			int t = *s.begin();
			ans += t;
			s.erase(s.find(t));
		}
	}
	
	cout << ans << endl;	
	
}