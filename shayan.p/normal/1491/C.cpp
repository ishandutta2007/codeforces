// better, faster, stronger
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5010;

int a[maxn], tdo[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	memset(tdo, 0, sizeof tdo);
	ll ans = 0;
	for(int i = 0; i < n; i++){
	    ans+= max(int(0), a[i]-1 -tdo[i]);
	    if(a[i]-1 < tdo[i])
		tdo[i+1]+= tdo[i] - (a[i]-1);
	    for(int j = i+2; j < min(n, i + a[i] + 1); j++)
		tdo[j]++;
	}
	cout << ans << "\n";
    }
    return 0;
}