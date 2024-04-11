// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int sum = 0, mn = inf, cnt = 0;
    for(int i = 0; i < 2*n-1; i++){
	int x;
	cin >> x;
	sum+= abs(x);
	mn = min(mn, abs(x));
	cnt+= x<0;
    }
    if((cnt & 1) && ((n & 1) == 0))
	cout << sum - 2 * mn << "\n";
    else
	cout << sum << "\n";
    return 0;
}