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

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

bool is[maxn][maxn];
int n;

bool check(int a, int b){
    if(a <= 0 || b <= 0 || a+2 > n || b+2 > n)
	return 0;
    for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++)
	    if(!is[a+i][b+j])
		return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int m;
    cin >> n >> m;
    for(int w = 0; w < m; w++){
	int x, y;
	cin >> x >> y;
	is[x][y] = 1;	
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
		if(check(x-i, y-j))
		    return cout << w+1 << endl, 0;
	    }
	}
    }
    return cout << -1 << endl, 0;
}