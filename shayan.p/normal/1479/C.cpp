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

int C = 2;
vector<pair<pii, int> > ans;

void build(int l, int r){
    vector<int> vrt;
    vrt.PB(1);
    for(int lg = 1; lg <= 20; lg++){
	int st = 1;
	ans.PB({{1, C}, 1});
	for(int i = 1; i < sz(vrt); i++){
	    ans.PB({{vrt[i], C}, st});
	    st+= (1<<(i-1));
	}
	vrt.PB(C);
	C++;
    }
    int st = l-1;
    for(int i = 20; i >= 1; i--){
	if(st + (1<<(i-1)) <= r){
	    ans.PB({{vrt[i], C}, st});
	    st+= (1<<(i-1));
	}
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int L, R;
    cin >> L >> R;
    build(max(int(2), L), R);
    if(L == 1)
	ans.PB({{1, C}, 1});
    cout << "YES\n";
    cout << C << " " << sz(ans) << endl;
    for(auto x : ans){
	int A = x.F.F, B = x.F.S, w = x.S;
	cout << A << " " << B << " " << w << "\n";
    }
    return 0;
}