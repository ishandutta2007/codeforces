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

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int a, b;
    cin >> a >> b;
    int sm = abs(a) + abs(b);
    pii p1 = {a > 0 ? sm : -sm, 0}, p2 = {0, b > 0 ? sm : -sm};
    if(p1.F > p2.F)
	swap(p1, p2);
    cout << p1.F << " " << p1.S << " " << p2.F << " " << p2.S << "\n";
    return  0;
}