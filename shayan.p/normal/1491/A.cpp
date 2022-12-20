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

const int maxn = 1e5 + 10;

bool a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	cnt+= a[i];
    }
    while(q--){
	int t, x;
	cin >> t >> x;
	if(t == 1){
	    x--;
	    cnt-= a[x];
	    a[x]^= 1;
	    cnt+= a[x];
	}
	else{
	    cout << (x <= cnt) << "\n";
	}
    }
    return 0;
}