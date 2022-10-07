#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<plli, vector<plli>, greater<plli> > PQ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
const ll infl = 1LL << 60;
char buf[1000000];
string nextLine() {
	scanf("%[^\n]", buf);
//	getc(stdin);
	scanf("%*c");
	return string(buf);
}
string next() {
	scanf("%s", buf);
	return string(buf);
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

map<string, int> mapp;
int kk = 1;
int m(string s) {
	if (mapp[s])
		return mapp[s];
	else
		return mapp[s] = kk++;
}
const int MAXN = 10;
int N;
int ar[MAXN];
int perm[MAXN];
int invs() {
	int cnt = 0;
	rep(i,N) {
		rep(j,i) {
			if (perm[j] > perm[i])
				cnt++;
		}
	}
	return cnt;
}
const int MAXM = 20;
const int MAXK = 30;
int M;
int ar2[MAXM][MAXK];
int cnts[MAXM];
bool isSubseq(int kk) {
	int k = 0;
	rep(i,cnts[kk]) {
		if (ar2[kk][i] == ar[perm[k]]) {
			k++;
		}
		if (k == N)
			break;
	}
	return k == N;
}

int main() {
	int best = 0;
	N = nextInt();
	rep(i,N) {
		ar[i] = m(next());
	}
	M = nextInt();
	rep(i,M) {
		int k = nextInt();
		cnts[i] = k;
		rep(j,k) {
			ar2[i][j] = m(next());
		}
	}
	int bestk = 0;
	rep(k,M) {
		int BB = 0;
		if (N >= 1) {
			rep(a,N) {
				perm[0] = a;
				if (N >= 2) {
					rep(b,N)
						if (a != b) {
							perm[1] = b;
							if (N >= 3) {
								rep(c,N)
									if (a != c && b != c) {
										perm[2] = c;
										if (N >= 4) {
											rep(d,N)
												if (a != d && b != d
														&& c != d) {
													perm[3] = d;
													int invsex = invs();
													if (isSubseq(k)) {
														BB = max(BB,
																N * (N - 1) / 2
																		- invsex
																		+ 1);
													}

												}
										} else {
											int invsex = invs();
											if (isSubseq(k)) {
												BB = max(BB,
														N * (N - 1) / 2 - invsex
																+ 1);
											}
										}
									}
							} else {
								int invsex = invs();
								if (isSubseq(k)) {
									BB = max(BB, N * (N - 1) / 2 - invsex + 1);
								}
							}
						}
				} else {
					int invsex = invs();
					if (isSubseq(k)) {
						BB = max(BB, N * (N - 1) / 2 - invsex + 1);
					}
				}
			}
		}

		if (BB) {
			if (BB > best) {
				best = BB;
				bestk = k;
			}
		}
	}
	if (best == 0) {
		cout << "Brand new problem!" << endl;
	} else {
		cout << (bestk + 1) << "\n";
		string ret = "[:";
		rep(i,best)
			ret += "|";
		ret += ":]";
		cout << ret << "\n";
	}
}