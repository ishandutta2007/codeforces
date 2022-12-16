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

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], cnt[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	--x;
	a[x] = i;
    }
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	--x;
	cnt[(i-a[x]+n)%n]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
	ans = max(ans, cnt[i]);
    }
    return cout << ans << endl, 0;
}