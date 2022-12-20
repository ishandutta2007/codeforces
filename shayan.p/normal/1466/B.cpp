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

int a[maxn];

int solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
	cin >> a[i];
    sort(a, a + n);
    int ans = 1;
    a[n-1]++;
    for(int i = n-2; i >= 0; i--){
	if(a[i] + 1 < a[i+1]){
	    ans++;
	    a[i]++;
	}
	else if(a[i] + 1 == a[i+1]){
	    ans++;
	}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
}