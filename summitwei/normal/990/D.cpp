#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005

bool adj[MAX_N][MAX_N];
bool toInvert;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, a, b;
	cin >> n >> a >> b;
	if(a > 1 && b > 1){
		cout << "NO\n";
		return 0;
	}
	if(n == 1){
		cout << "YES\n0\n";
		return 0;
	}
	if(n <= 3 && a == 1 && b == 1){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	
	if(b != 1){
		toInvert = true;
		a = b;
	}
	
	for(int i=n-1; i>=a; i--){
		adj[0][i] = true;
		adj[i][0] = true;
	}
	
	if(a == 1){
		adj[0][n-1] = false;
		adj[n-1][0] = false;
		adj[n-2][n-1] = true;
		adj[n-1][n-2] = true;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j){
				cout << 0;
				continue;
			}
			
			bool toOutput = (adj[i][j] != toInvert);
			cout << toOutput;
		}
		cout << "\n";
	}
	
    return 0;
}