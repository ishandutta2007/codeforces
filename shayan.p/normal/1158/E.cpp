// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1010, mod = 1e9 + 7;
const ll inf = 1e18;

int h[maxn];
bool calced[maxn];
vector<int> vh[maxn];
int arr[maxn], n;
int par[maxn];

bitset<maxn> ask(){
    cout << "? ";
    for(int i = 0; i < n; i++)
	cout << min( arr[i], n-1 ) <<" ";
    cout << endl;
    string s;
    cin >> s;
    bitset<maxn> bs;
    for(int i = 0; i < n; i++)
	bs[i] = s[i] == '1';
    return bs;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    cin >> n;
    vh[0].PB(0);
    calced[0] = 1;
    
    for(int bt = 9; bt>=0; bt--){
	memset(arr, 0, sizeof arr);
	for(int i = 0; i < n && !vh[i].empty(); i+= 1<<(bt+2)){
	    for(int u : vh[i])
		arr[u] = 1<<bt;
	}
	bitset<maxn> A = ask();

	memset(arr, 0, sizeof arr);
	for(int i = 0; i < n && !vh[i].empty(); i+= 1<<(bt+2)){
	    for(int u : vh[i])
		arr[u] = (1<<bt)-1;
	}
	bitset<maxn> B = ask();

	for(int i = 0; i < n; i++){
	    if(bit(h[i], bt+1) == 0){
		if(!B[i]){
		    if(calced[i])
			continue;
		    h[i]+= 1<<bt;
		    if(A[i]){
			vh[ h[i] ].PB(i);
			calced[i] = 1;
		    }
		}
	    }
	}
	
	memset(arr, 0, sizeof arr);
	for(int i = 1<<(bt+1) ; i < n && !vh[i].empty(); i+= 1<<(bt+2)){
	    for(int u : vh[i])
		arr[u] = 1<<bt;
	}
	A = ask();

	memset(arr, 0, sizeof arr);
	for(int i = 1<<(bt+1) ; i < n && !vh[i].empty(); i+= 1<<(bt+2)){
	    for(int u : vh[i])
		arr[u] = (1<<bt)-1;
	}
	B = ask();

	for(int i = 0; i < n; i++){
	    if(bit(h[i], bt+1) == 1){
		if(calced[i])
		    continue;
		if(!B[i]){
		    h[i]+= 1<<bt;
		    if(A[i]){
			vh[ h[i] ].PB(i);
			calced[i] = 1;
		    }
		}
	    }
	}
    }

    for(int md = 0; md < 3; md++){
	for(int bt = 0; bt <= 9; bt++){
	    memset(arr, 0, sizeof arr);
	    for(int u = 0; u < n; u++){
		if((h[u] % 3 == md) && bit(u, bt))
		    arr[u] = 1;
	    }
	    bitset<maxn> bs = ask();
	    for(int u = 0; u < n; u++){
		if((h[u] + 2) % 3 == md){
		    par[u]+= bs[u]<<bt;
		}
	    }
	}
    }

    cout << "!" << endl;
    for(int i = 1; i < n; i++){
	cout << i+1 << " " << par[i] + 1 <<endl;
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")