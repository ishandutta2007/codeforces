// Never let them see you bleed...
// Shayan.P  2020-06-18

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

vector<pii> ans;

void add(int x, int y){
    ans.PB({100 + x, 100 + y});
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int x = 0, y = 0;
    for(int i = 0; i < n/2; i++){
	add(x, y);
	add(x+1, y);
	add(x, y-1);
	add(x+1, y-1);
	add(x, y+1);
	add(x+1, y+1);
	add(x+2, y);
	x+= 3;
    }
    add(x, y);
    x++;
    int X = x, Y = y;
    for(int i = 0; i < 7; i++){
	add(x, y);
	y--;
    }
    while(x >= -2){
	add(x, y);
	x--;
    }
    while(y < 0){
	add(x, y);
	y++;	
    }
    while(x < 0){
	add(x, y);
	x++;
    }
    if(n & 1){
	add(X+1, Y);
	add(X+2, Y);
	add(X+2, Y+1);
	add(X+2, Y+2);
	add(X+1, Y+2);
	add(X, Y+2);
	add(X, Y+1);
    }
    cout << sz(ans) << "\n";
    for(pii p : ans){
	cout << p.F << " " << p.S << "\n";
    }
    return 0;
}