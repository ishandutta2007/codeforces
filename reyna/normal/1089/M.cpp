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
const int maxn = 100;
vector<int> out[maxn], in[maxn];
vector<int> ts;
int mark[maxn], col[maxn];
void dfs(int v){
	if(mark[v]++)
		return;
	for(auto u : out[v])
		dfs(u);
	ts.push_back(v);
}
int tim;
vector<int> pos[maxn];
void sfd(int v){
	if(mark[v]++)
		return;
	col[v] = tim;
	pos[tim].push_back(v);
	for(auto u : in[v])
		sfd(u);
}
int can[maxn][maxn];
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			int g;
			cin >> g;
			if(g){
				out[i].push_back(j);
				in[j].push_back(i);
			}
		}
	for(int i=0; i<n; i++)
		dfs(i);
	reverse(ALL(ts));
	memset(mark, 0, sizeof mark);
	for(int i : ts){
		if(!mark[i]){
			sfd(i);
			tim++;
		}
	}
	for(int i=0; i<n; i++){
		for(auto u : out[i]){
			if(col[u] != col[i])
				can[col[i]][col[u]] = 1;
		}
	}
	/*for(int i=0; i<n; i++)
		cout << i << ": " << col[i] << endl;
	*/
	cout << "18 3 " << (tim) * 2 << endl;
	for(int i=0; i<tim; i++){
		for(int j=0; j<tim; j++)
			cout << ".#";
		for(int j=8 - tim; j>=0; j--)
			cout << "##";
		cout << endl;
		for(int j=0; j<tim; j++){
			if(can[i][j] || i == j)
				cout << ".#";
			else
				cout << "##";
		}
		for(int j=8 - tim; j>=0; j--)
			cout << "##";
		cout << endl;
		for(auto j : pos[i]){
			cout << j+1;
		}
		for(int j=17-pos[i].size(); j >= 0; j--)
			cout << ".";
		cout << endl;
		cout << endl;
		for(int j=0; j<tim; j++)
			if(i != j)
				cout << ".#";
			else
				cout << "##";
		for(int j=8 - tim; j>=0; j--)
			cout << "##";
		cout << endl;
		for(int j=0; j<18; j++)
			cout << "#";
		cout << endl;
		for(int j=0; j<18; j++)
			cout << "#";
		cout << endl;
		cout << endl;
		
	}	
}