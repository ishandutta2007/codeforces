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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e9 + 10;

ll a[3];
int b[3], lst = -1;

void Do(ll x){
    cout << x << endl;
    int id;
    cin >> id;
    if(id == 0)
	exit(0);
    --id;
    a[id]+= x;
    sort(b, b+3, [&](int i, int j){ return a[i] < a[j]; } );
    lst = id;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> a[0] >> a[1] >> a[2];
    iota(b, b+3, 0);
    sort(b, b+3, [&](int i, int j){ return a[i] < a[j]; } );
    
    cout << "First" << endl;
    Do(inf);
    Do(a[b[2]] - a[b[0]] + a[b[2]] - a[b[1]]);
    Do(a[b[1]] - a[b[0]]);
    return 0;
}