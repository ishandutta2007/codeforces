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

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];
pii b[maxn];
vector<pii> ans;
int P[maxn];

void Swap(int i, int j){
    P[a[i]] = j;
    P[a[j]] = i;
    swap(a[i], a[j]);
    ans.PB({i, j});
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	b[i] = {a[i], i};
    }
    sort(b, b+n);
    for(int i = 0; i < n; i++){
	a[i] = lower_bound(b, b+n, (pii){a[i], i}) - b;
	P[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
	while(a[i] > i)
	    Swap(i, P[a[i]-1]);
    }
    cout << sz(ans) << "\n";
    for(pii p : ans)
	cout << p.F+1 << " " << p.S+1 << "\n";
    return 0;
}