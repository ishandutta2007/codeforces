#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

ll a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    sort(a, a + n);
    for(int i = n-1; i >= 0; i--){
	a[i]+= a[i+1];
    }
    int can = k+1;
    ll ans = 0;
    int pt = 0;
    while(pt < n){
	int did = 0;
	do{
	    can--;
	    pt++;
	    did++;
	}while(pt < n && can > 0 && a[pt] < 0);
	ans+= a[pt];
	can = did;
    }
    return cout << ans << endl, 0;
}