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

bool is[maxn];
int now;

int ask(vector<int> &vec){
    cout << sz(vec) << " ";
    for(int x : vec){
	cout << x+1 << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int bestk = 0, ans = 0;
    for(int k = 1; k <= n; k++){
	int num = n + 1 - k - (n+k-1)/k;
	if(num > ans)
	    ans = num, bestk = k;
    }
    while(now < ans){
	vector<int> vec;	
	for(int i = 0; i < n; i++){
	    if(sz(vec) < bestk && i % bestk != 0 && is[i] == 0)
		vec.PB(i), is[i] = 1;
	}
	assert(sz(vec) == bestk);
	now+= bestk;
	int st = ask(vec) - 1;
	for(int i = 0; i < bestk; i++){
	    int id = (st + i) % n;
	    now-= is[id];
	    is[id] = 0;
	}
    }
    return cout << 0 << endl, 0;
}