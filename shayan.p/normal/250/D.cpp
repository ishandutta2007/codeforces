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

int A[maxn], B[maxn], L[maxn], a, b;

double calc(int i, int j){
    return sqrt(1ll * a*a + 1ll * A[i]*A[i]) + L[j] + sqrt( 1ll * (a-b) * (a-b) + 1ll * (A[i]-B[j]) * (A[i]-B[j]) );
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m >> a >> b;

    for(int i = 0; i < n; i++){
	cin >> A[i];
    }
    for(int i = 0; i < m; i++){
	cin >> B[i];
    }
    for(int i = 0; i < m; i++){
	cin >> L[i];
    }
    
    double ans = inf;
    int ans1 = -1, ans2 = -1;
    int pos = 0;
    for(int i = 0; i < m; i++){
	while(pos+1 < n && calc(pos+1, i) < calc(pos, i))
	    pos++;
	if(ans > calc(pos, i))
	    ans = calc(pos, i), ans1 = pos, ans2 = i;
    }
    return cout << ans1+1 << " " << ans2+1 << endl, 0;
}