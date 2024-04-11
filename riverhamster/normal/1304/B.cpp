#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

string s[105], rs[105];
bool vis[105];

int main(){
	// File("b");
	int n, m;
	cin >> n >> m;
	deque<string> q1, q2;
	int res = 0;
	for(int i=1; i<=n; i++){
		cin >> s[i];
		rs[i] = s[i];
		reverse(rs[i].begin(), rs[i].end());
		for(int j=1; j<i; j++)
			if(!vis[j] && s[i] == rs[j]){
				q1.push_back(s[i]); q2.push_front(s[j]);
				vis[i] = vis[j] = true;
				res += 2;
			}
	}
	string Mid = "";
	for(int i=1; i<=n; i++){
		if(!vis[i] && s[i] == rs[i]){
			Mid = s[i];
			break;
		}
	}
	cout << res * m + Mid.size() << endl;
	for(string now : q1) cout << now;
	cout << Mid;
	for(string now : q2) cout << now;
	cout << endl;
	return 0;
}