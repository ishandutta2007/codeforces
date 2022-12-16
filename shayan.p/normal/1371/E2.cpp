// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-06
 
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
 
int a[maxn], cnt[2 * maxn];
vector<int> v[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, p;
    cin >> n >> p;
    int mx = 0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	mx = max(mx, a[i]);
    }
    for(int i = 0; i < n; i++){
	a[i] = max(int(0), a[i] - mx + n-1);
	cnt[a[i]]++;
    }
    for(int i = 1; i <= 2*n; i++){
	cnt[i]+= cnt[i-1];
    }
    for(int i = 0; i <= 2*n; i++){
	cnt[i]-= i;
	cnt[i] = ((cnt[i]%p) + p)%p;
	v[(p - cnt[i]) % p].PB(i);	
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
	auto it = lower_bound(v[i%p].begin(), v[i%p].end(), i);
	if(it == v[i%p].end() || (*it) - i >= n)
	    ans.PB(i);
    }
    cout << sz(ans) << "\n";
    for(int x : ans){
	cout << x + mx - n + 1 << " ";
    }
    return 0;
}