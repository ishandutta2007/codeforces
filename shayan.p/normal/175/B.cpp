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

map<string, int> mp;
vector<pair<int, string> > vec;
int val[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	string s;
	int x;
	cin >> s >> x;
	mp[s] = max(mp[s], x);
    }
    for(auto p : mp){
	vec.PB({p.S, p.F});
    }
    cout << sz(vec) << "\n";
    sort(vec.begin(), vec.end());
    for(int i = sz(vec)-1; i >= 0; i--){
	val[i] = val[i+1];
	if(i != sz(vec)-1 && vec[i].F != vec[i+1].F)
	    val[i] = sz(vec)-i-1;
	
	 if(val[i] * 100 > 50 * sz(vec))
	    cout << vec[i].S << " noob\n";
	else if(val[i] * 100 > 20 * sz(vec))
	    cout << vec[i].S << " random\n";
	else if(val[i] * 100 > 10 * sz(vec))
	    cout << vec[i].S << " average\n";
	else if(val[i] * 100 > 1 * sz(vec))
	    cout << vec[i].S << " hardcore\n";
	else
	    cout << vec[i].S << " pro\n";	
    }
    return 0;
}