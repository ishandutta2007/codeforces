#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	set<int> st;
	for(int x : v)
	    for(int y : v)
		st.insert(abs(x-y));
	cout << sz(st)-1 << "\n";
    }
    return 0;
}