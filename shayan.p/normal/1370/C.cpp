// Never let them see you bleed...
// Shayan.P  2020-06-30

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

bool isp(int n){
    for(int i = 2; i*i <= n; i++)
	if(n % i == 0)
	    return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	int cnt = 0;
	while(!(n & 1))
	    cnt++, n>>=1;
	if(cnt == 1){
	    if(n == 1 || !isp(n))
		cout << "Ashishgup\n";
	    else
		cout << "FastestFinger\n";
	}
	else{
	    if(n == 1)
		cout << "FastestFinger\n";
	    else
		cout << "Ashishgup\n";
	}
    }
    return 0;
}