// And you curse yourself for things you never done

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = (1<<9) + 10, maxm = 100;

ll a[maxn][maxn], b[maxn][maxn];
pii p[maxn], q[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int N = (1<<n);
    for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
	    cin >> a[i][j];
	}
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
	cin >> p[i].F >> p[i].S;
    }
    for(int i = m-1; i >= 0; i--){
	p[i].F = (p[i].F - p[0].F + N) % N;
	p[i].S = (p[i].S - p[0].S + N) % N;
    }
    for(int stp = 0; stp < n; stp++){
	for(int i = 0; i < m; i++){
	    q[i].F = (p[i].F << (n-1-stp)) % N;
	    q[i].S = (p[i].S << (n-1-stp)) % N;
	}
	memset(b, 0, sizeof b);
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++){
		for(int k = 0; k < m; k++){
		    b[(i + q[k].F) % N][(j + q[k].S) % N]^= a[i][j];
		}
	    }
	}
	memcpy(a, b, sizeof a);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
	    ans+= a[i][j] > 0;
	}	
    }
    return cout << ans << endl, 0;
}