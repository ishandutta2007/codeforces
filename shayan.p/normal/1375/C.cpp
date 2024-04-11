// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-04

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 3e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	cout << (a[0] < a[n-1] ? "YES\n" : "NO\n");
    }
    return 0;
}