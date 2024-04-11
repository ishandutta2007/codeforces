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

const int maxn = 1e5 + 10, inf = 1e9;

int n;

int ask(int x){
    if(x == 0 || x == n+1)
	return inf;
    cout << "? " << x << endl;
    cin >> x;
    return x;
}
void tell(int x){
    cout << "! " << x << endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    cin >> n;
    int l = 0, r = n+1;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	int A = ask(mid-1), B = ask(mid), C = ask(mid+1);
	if(A > B && B < C)
	    tell(mid);
	if(B > C)
	    l = mid;
	else
	    r = mid;
    }
}