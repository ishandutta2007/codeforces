// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 510, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	map<pii, int> cnt;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i < n; i++)
	    cin >> b[i];
	for(int i = 0; i < n; i++){
	    cnt[{a[i], a[n-1-i]}]++;
	    cnt[{b[i], b[n-1-i]}]--;
	}
	bool is = 1;
	if((n & 1) && (a[n/2] != b[n/2]))
	    is = 0;
	for(auto p : cnt)
	    is&= p.S == 0;
	if(is)
	    cout << "yes\n";
	else
	    cout << "No\n";
    }
    return 0;
}