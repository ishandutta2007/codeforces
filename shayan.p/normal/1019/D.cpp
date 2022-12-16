// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define X first
#define Y second
#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int, int> point;
typedef pair<int, int> pii;

const int maxn = 2010;
const double PI = acos(-1);

istream& operator >> (istream& in, point &p){
    in >> p.X >> p.Y;
    return in;
}
ostream& operator << (ostream& out, point p){
    out << p.X << " " << p.Y;
    return out;
}
point operator - (point a, point b){
    return { a.X - b.X, a.Y - b.Y };
}
ll operator * (point a, point b){
    return 1ll * a.X * b.Y - 1ll * a.Y * b.X;
}

point p[maxn];
vector<pii> vec;

int arr[maxn], pos[maxn];

void print(int a, int b, int c){
    cout << "Yes\n" << p[a] << "\n" << p[b] << "\n" << p[c] << "\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    ll S;
    cin >> S;
    S*=2;
    
    for(int i = 0; i < n; i++)
	cin >> p[i], pos[i] = arr[i] = i;
    sort( p, p + n, [](point a, point b){ return a.Y == b.Y ? a.X < b.X : a.Y < b.Y; } );
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	    if(i != j)
		vec.PB( {i, j} );
    sort( vec.begin(), vec.end() , [](pii i, pii j){
	    point A = p[i.F] - p[i.S], B = p[j.F] - p[j.S];	    
	    int _A = A.Y < 0 || (A.Y == 0 && A.X < 0);
	    int _B = B.Y < 0 || (B.Y == 0 && B.X < 0);
	    return _A != _B ? _A < _B : A * B > 0; 
	    
	});
    
    
    for(auto it : vec){
	int a = it.F, b = it.S;
	swap( pos[a], pos[b] );
	swap( arr[ pos[a] ], arr[ pos[b] ] );

	auto f = [&](int c){ return (p[a] - p[b]) * (p[c] - p[b]); };
	
	int l = -1, r = n; // 0 -> kamtar az S 1 -> bishtar mosavi
 	while( r - l > 1 ){
	    int mid = (l + r) /2;
	    if( f( arr[mid] ) < S )
		l = mid;
	    else
		r = mid;
	}
	if( r != n && f( arr[r] ) == S )
	    print(a, b, arr[r]);
    }
    return cout << "No\n", 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")