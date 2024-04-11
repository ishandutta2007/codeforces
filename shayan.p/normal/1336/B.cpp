// Never let them see you bleed...
// Shayan.P  2020-04-15

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 5e18 + 10;

vector<int> vec[3];
int prm[3];

ll tw(ll a){
    return a*a;
}
ll calc(ll a, ll b, ll c){
    return tw(a-b) + tw(a-c) + tw(b-c);
}
ll solve(){
    for(int i = 0; i < 3; i++)
	sort(vec[i].begin(), vec[i].end());
    iota(prm, prm+3, 0);
    ll ans = inf;
    do{
	int pt1 = 0, pt2 = 0;
	for(int i = 0; i < sz(vec[prm[0]]); i++){
	    while(pt1+1 < sz(vec[prm[1]]) && vec[prm[1]][pt1+1] <= vec[prm[0]][i])
		pt1++;
	    while(pt2 < sz(vec[prm[2]]) && vec[prm[2]][pt2] < vec[prm[0]][i])
		pt2++;
	    if(pt2 == sz(vec[prm[2]]))
		break;
	    ans = min(ans, calc(vec[prm[0]][i], vec[prm[1]][pt1], vec[prm[2]][pt2]));
	}
    }while(next_permutation(prm, prm+3));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vec[0].resize(n1), vec[1].resize(n2), vec[2].resize(n3);
	for(int i = 0; i < n1; i++)
	    cin >> vec[0][i];
	for(int i = 0; i < n2; i++)
	    cin >> vec[1][i];
	for(int i = 0; i < n3; i++)
	    cin >> vec[2][i];
	cout << solve() << "\n";
    }
    return 0;
}