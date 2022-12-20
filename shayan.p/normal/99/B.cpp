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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    int sm = 0;
    for(int i = 0; i < n; i++){
	sm+= a[i];
    }
    if(sm % n != 0)
	return cout << "Unrecoverable configuration.\n", 0;
    sm/=n;
    vector<int> v;
    for(int i = 0; i < n; i++){
	if(a[i] != sm)
	    v.PB(i);
    }
    if(sz(v) > 2)
	return cout << "Unrecoverable configuration.\n", 0;
    if(sz(v) == 0)
	return cout << "Exemplary pages.\n", 0;
    int A = v[0], B = v[1];
    if(a[A] > a[B])
	swap(A, B);
    cout << (a[B]-a[A])/2 << " ml. from cup #" << A+1 << " to cup #" << B+1 << ".\n";
    return 0;
}