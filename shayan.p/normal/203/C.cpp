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

    int n, d, A, B;
    cin >> n >> d >> A >> B;
    vector<pii> v;
    for(int i = 0; i < n; i++){
	int a, b;
	cin >> a >> b;
	v.PB({a*A + b*B, i});
    }
    sort(v.begin(), v.end());
    ll num = 0;
    int pt = 0;
    while(pt < n && num + v[pt].F <= d){
	num+= v[pt].F;
	pt++;
    }
    cout << pt << "\n";
    for(int i = 0; i < pt; i++)
	cout << v[i].S + 1 << " ";
    cout << "\n";
    return 0;
}