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

vector<int> v[maxn];
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> a[i];
	v[a[i]].PB(i);
    }
    int A = 0, B = 0, ans = 0;
    for(int i = n; i >= 1; i--){
	v[a[i]].pop_back();
	if(a[i] != A && a[i] != B){
	    int ta = v[A].empty() ? -1 : v[A].back(), tb = v[B].empty() ? -1 : v[B].back();
	    ans++;
	    if(ta > tb)
		A = a[i];
	    else
		B = a[i];
	}
	else if(a[i] != A){
	    ans++;
	    A = a[i];
	}
	else if(a[i] != B){
	    ans++;
	    B = a[i];
	}
    }
    return cout << ans << endl, 0;
}