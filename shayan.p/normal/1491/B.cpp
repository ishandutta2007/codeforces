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

const int maxn = 1e6 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++){
	    cin >> a[i];	    
	}
	bool can = 1, eq = 1;
	for(int i = 0; i < n-1; i++){
	    can&= abs(a[i] - a[i+1]) <= 1;
	    eq&= a[i] == a[i+1];
	}
	if(can == 0){
	    cout << 0 << "\n";
	}
	else if(eq == 0){
	    cout << min(x, y) << "\n";
	}
	else{
	    cout << min(y + y, x + y) << "\n";
	}
    }
    return 0;
}