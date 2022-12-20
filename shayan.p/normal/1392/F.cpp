// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

ll a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    ll sm = 0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	sm+= a[i];
    }
    --n;
    for(int i = 0; i < n; i++){
	a[i] = a[i+1] - a[i];
    }
    a[n] = 0;

    a[1]+= a[0]/2;
    a[0] = a[0]&1;

    priority_queue<int> zrs;
    if(a[0] == 0)
	zrs.push(0);
    
    for(int i = 1; i < n; i++){
	while(!zrs.empty()){
	    int x = zrs.top();
	    if(i-x-1 +2 <= a[i]){
		zrs.pop();
		a[x] = 1;
		a[i]-= i-x-1 +2;
		a[i+1]+= i-x-1 + 1;
	    }
	    else if(a[i] > 1){
		zrs.pop();
		a[x] = 1;
		int cnt = a[i] - 1;
		zrs.push(x + cnt);
		a[x + cnt] = 1;
		a[i] = 1;
		a[i+1]+= cnt;
	    }
	    else{
		break;
	    }
	}
	if(zrs.empty()){
	    ll c = a[i] / (i+2);
	    a[i+1]+= c * (i+1);
	    a[i]%= (i+2);
	    if(a[i] > 1){
		zrs.push(a[i] - 2);
		a[ a[i]-2 ] = 0;
		a[i+1]+= a[i]-1;
		a[i] = 1;
	    }		
	}
	if(a[i] == 0){
	    zrs.push(i);
	}
    }
    a[n] = 0;
    
    for(int i = 1; i < n; i++){
	a[i]+= a[i-1];
    }
    ll sm2 = 0;
    for(int i = n; i >= 1; i--){
	a[i] = a[i-1];
	sm2+= a[i];
    }
    n++;
    assert((sm - sm2) % n == 0);
    a[0] = (sm - sm2) / n;
    for(int i = 1; i < n; i++){
	a[i]+= a[0];
    }
    for(int i = 0; i < n; i++){
	cout << a[i] << " ";
    }
    return cout << endl, 0;
}