// And you curse yourself for things you never done
// Shayan.P  2020-08-12

#include<bits/stdc++.h>

#define F first
#define S second
#define X F
#define Y S.F
#define Z S.S
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> point;
typedef pair<point, point> cube;

const int maxn = 5e5 + 10, SQ = 1010, inf = 1e9;

cube operator & (cube a, cube b){
    point A, B;
    A.X = max(a.F.X, b.F.X);
    A.Y = max(a.F.Y, b.F.Y);
    A.Z = max(a.F.Z, b.F.Z);
    B.X = min(a.S.X, b.S.X);
    B.Y = min(a.S.Y, b.S.Y);
    B.Z = min(a.S.Z, b.S.Z);
    return {A, B};
}

pii p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	string s;
	cin >> s;
	for(char c : s){
	    if(c == 'B')
		p[i].F++;
	    else
		p[i].S++;
	}
    }
    int L = -1, R = 4 * maxn;
    pii ans;
    while(R-L > 1){
	int mid = (L+R) >> 1;
	cube c = { {0, {0, -inf}}, {inf, {inf, inf}} };
	for(int i = 0; i < n; i++){
	    point pt = {p[i].F, {p[i].S, p[i].F - p[i].S}};
	    cube d = { {pt.X - mid, {pt.Y - mid, pt.Z - mid}}, {pt.X + mid, {pt.Y + mid, pt.Z + mid}} };
	    c = c & d;
	}
	if(c.F.X <= c.S.X && c.F.Y <= c.S.Y && c.F.Z <= c.S.Z){
	    int low = c.F.X - c.S.Y;
	    int high = c.S.X - c.F.Y;
	    if(max(low, c.F.Z) <= min(high, c.S.Z)){
		int d = min(high, c.S.Z);
		if(d < c.S.X - c.S.Y)
		    ans = {c.F.X + d - low, c.S.Y};
		else
		    ans = {c.S.X, c.S.Y - (d - (c.S.X - c.S.Y))};
		R = mid;
	    }
	    else{
		L = mid;
	    }
	}
	else{
	    L = mid;
	}	
    }
    
    for(int i = 0; i < n; i++)
    	assert(abs(ans.F - p[i].F) <= R), assert(abs(ans.S - p[i].S) <= R), assert(abs(ans.F - ans.S - p[i].F + p[i].S) <= R);

    if(ans.F == 0 && ans.S == 0)
	ans = {1, 1};
    cout << R << "\n";
    for(int i = 0; i < ans.F; i++)
	cout << 'B';
    for(int i = 0; i < ans.S; i++)
	cout << 'N';
    return cout << endl, 0;	
}