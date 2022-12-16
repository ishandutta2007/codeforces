// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-24

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 255, mod = 1e9 + 7, inf = 1e9 + 10;

int A[maxn], B[maxn];
bool isA[maxn * maxn], isB[maxn * maxn];
int ans[maxn][maxn];

set<pii> st;
int ptA = 1, ptB = 1;
int n, m;

bool ok(int x, int y){
    if(x >= ptA || y >= ptB)
	return 0;
    if(ans[x][y] != 0)
	return 0;
    if( !(x == 0 || ans[x-1][y] != 0) && !(x == n || ans[x+1][y] != 0) )
	return 0;
    if( !(y == 0 || ans[x][y-1] != 0) && !(y == m || ans[x][y+1] != 0) )
	return 0;
    return 1;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void chk1(int u){
    for(int i = 1; i <= ptB; i++)
	if(ok(u, i))
	    st.insert({u, i});
}
void chk2(int u){
    for(int i = 1; i <= ptA; i++)
	if(ok(i, u))
	    st.insert({i, u});
}
void fll(int a, int b, int c){
    ans[a][b] = c;
    st.erase({a, b});
    for(int i = 0; i < 4; i++){
	int x = a + dx[i], y = b + dy[i];
	if(x >= 1 && y >= 1 && x <= n && y <= m && ok(x, y))
	    st.insert({x, y});
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
	for(int j = 1; j <= m; j++){
	    int x;
	    cin >> x;
	    A[i] = max(A[i], x);
	    B[j] = max(B[j], x);
	}
    }
    for(int i = 1; i <= n; i++){
	isA[ A[i] ] = 1;	
    }
    for(int i = 1; i <= m; i++){
	isB[ B[i] ] = 1;
    }
    for(int i = n*m; i >= 1; i--){
	if(isA[i] && isB[i]){
	    fll(ptA, ptB, i);
	    ptA++, ptB++;
	    chk1(ptA - 1), chk2(ptB - 1);
	}
	else if(isA[i]){
	    fll(ptA, ptB-1, i);
	    ptA++;
	    chk1(ptA - 1);
	}
	else if(isB[i]){
	    fll(ptA-1, ptB, i);
	    ptB++;
	    chk2(ptB - 1);
	}
	else{
	    pii p = *st.begin();	    
	    fll(p.F, p.S, i);
	}
    }
    for(int i = 1; i <= n; i++){
	for(int j = 1; j <= m; j++)
	    cout << ans[i][j] << " \n"[j == m];
    }
    return 0;
}