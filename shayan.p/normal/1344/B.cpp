// Never let them see you bleed...
// Shayan.P  2020-05-06

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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
	     
string s[maxn];
bool mark[maxn][maxn];
int n, m, ans;

void dfs(int x, int y){
    mark[x][y] = 1;
    for(int i = 0; i < 4; i++){
	int X = x + dx[i], Y = y + dy[i];
	if(X >= 0 && Y >= 0 && X < n && Y < m && s[X][Y] == '#'  && !mark[X][Y])
	    dfs(X, Y);
    }
}
bool ok(string s){
    int pt1 = 0, pt2 = sz(s)-1;
    while(pt1 < sz(s) && s[pt1] == '.')
	pt1++;
    while(pt2 >= 0 && s[pt2] == '.')
	pt2--;
    for(int i = pt1; i <= pt2; i++)
	if(s[i] == '.')
	    return 0;
    return 1;    
}
bool emp(string s){
    for(char c : s)
	if(c != '.')
	    return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> m;
    for(int i = 0; i < n; i++){
	cin >> s[i];
    }
    int num1 = 0, num2 = 0;
    for(int i = 0; i < n; i++){
	if(!ok(s[i]))
	    return cout << -1 << endl, 0;
	num1+= emp(s[i]);
    }
    for(int j = 0; j < m; j++){
	string S;
	for(int i = 0; i < n; i++)
	    S+= s[i][j];
	if(!ok(S))
	    return cout << -1 << endl, 0;
	num2+= emp(S);
    }
    if(num1 > num2)
	swap(num1, num2);
    if(num1 == 0 && num2 != 0)
	return cout << -1 << endl, 0;
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    if(mark[i][j] == 0 && s[i][j] == '#')
		dfs(i, j), ans++;
	}
    }
    return cout << ans << endl, 0;
}