// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-04

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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 1; i < n; i+=2){
	    if(abs(a[i-1]) < abs(a[i])){
		a[i] = abs(a[i]);
		a[i+1] = -abs(a[i+1]);
	    }
	    else{
		if(a[i-1] <= a[i]){
		    a[i] = abs(a[i]);
		    a[i+1] = -abs(a[i+1]);
		}
		else{
		    a[i] = -abs(a[i]);
		    a[i+1] = abs(a[i+1]);
		}
	    }
	}
	for(int i = 0; i < n; i++){
	    cout << a[i] << " ";
	}
	cout << "\n";
    }
    return 0;
}