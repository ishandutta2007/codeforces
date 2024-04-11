#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

int main () {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	forn(i,k){
		int x,y;
		cin>>x>>y;
		if (x < 6 || x > n - 5 || y < 6 || y > m - 5) {
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}