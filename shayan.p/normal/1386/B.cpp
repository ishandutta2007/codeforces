// hello darkness my old friend, I've come to talk with you again

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


struct Point{
    ll X, Y, Z;
    Point(ll X, ll Y, ll Z) : X(X), Y(Y), Z(Z) {}
    Point(){ X = Y = Z = 0; }
};
Point zr;

Point operator * (Point a, Point b){
    return { a.Y * b.Z - a.Z * b.Y, -a.X * b.Z + a.Z * b.X, a.X * b.Y - a.Y * b.X }; 
}
ll operator ^ (Point a, Point b){
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}
Point operator * (ll x, Point a){
    return {a.X * x, a.Y * x, a.Z * x};
}
Point operator + (Point a, Point b){
    return {a.X + b.X, a.Y + b.Y, a.Z + b.Z};
}
Point operator - (Point a, Point b){
    return {a.X - b.X, a.Y - b.Y, a.Z - b.Z};
}
bool operator == (Point a, Point b){
    return a.X == b.X && a.Y == b.Y && a.Z == b.Z;
}
bool operator != (Point a, Point b){
    return !(a == b);
}
ll ffC(Point a, Point b, Point c){
    return ((a * b) ^ c);
}
bool inL(Point a, Point b){
    return a * b == zr;
}
bool one_side(Point a, Point b){
    if(a.X != 0 && b.X != 0)
	return !((a.X > 0) ^ (b.X > 0));
    if(a.Y != 0 && b.Y != 0)
	return !((a.Y > 0) ^ (b.Y > 0));
    if(a.Z != 0 && b.Z != 0)
	return !((a.Z > 0) ^ (b.Z > 0));
    assert(0);
}

struct Segment{
    int val[4 * maxn], lz[4 * maxn];
    void shift(int l, int r, int id){
	val[id]+= lz[id];
	if(r-l > 1)
	    lz[2*id]+= lz[id], lz[2*id+1]+= lz[id];
	lz[id] = 0;	
    }
    void add(int f, int s, int x, int l = 0, int r = maxn, int id = 1){
	if(f >= s || l >= r)
	    return;
	shift(l, r, id);
	if(s <= l || r <= f)
	    return;
	if(f <= l && r <= s){
	    lz[id] = x;
	    shift(l, r, id);
	    return;
	}
	int mid = (l+r) >> 1;
	add(f, s, x, l, mid, 2*id);
	add(f, s, x, mid, r, 2*id+1);
	val[id] = min(val[2*id], val[2*id+1]);
    }
    int ask(int f, int s, int l = 0, int r = maxn, int id = 1){
	if(f >= s || l >= r)
	    return 1;
	shift(l, r, id);
	if(s <= l || r <= f)
	    return 1;
	if(f <= l && r <= s)
	    return val[id];
	int mid = (l+r) >> 1;
	return min(ask(f, s, l, mid, 2*id), ask(f, s, mid, r, 2*id+1));
    }
};Segment seg1, seg2;

Point p[maxn], center;
int ONE, TWO, N, fx;
int cnt[2][maxn], ID[maxn];

bool up(Point pt){
    ll num = ffC(center, p[fx], pt);
    if(num != 0)
	return num > 0;
    return one_side(center * p[fx], center * pt);
}
void add(int id){
    if(inL(center, p[id])){
	ONE++;
	return;
    }
    bool o = up(p[id]);
    if(++cnt[o][ID[id]] == 1 && cnt[!o][ID[id]]){
	TWO++;
    }
    if(o){
	seg1.add(ID[id]+1, N, 1);
	seg2.add(0, ID[id], 1);
    }
    else{
	seg1.add(0, ID[id], 1);
	seg2.add(ID[id]+1, N, 1);
    }
}
void era(int id){
    if(inL(center, p[id])){
	ONE--;
	return;
    }
    bool o = up(p[id]);
    if(--cnt[o][ID[id]] == 0 && cnt[!o][ID[id]]){
	TWO--;
    }
    if(o){
	seg1.add(ID[id]+1, N, -1);
	seg2.add(0, ID[id], -1);
    }
    else{
	seg1.add(0, ID[id], -1);
	seg2.add(ID[id]+1, N, -1);
    }
}
int solve(){
    if(ONE)
	return 1;
    if(TWO)
	return 2;
    if(N == 0 || seg1.ask(0, N) == 0 || seg2.ask(0, N) == 0) // even N < 3
	return 0;
    return 3;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    
    cin >> center.X >> center.Y >> center.Z;
    int q, C = 0;
    
    vector< pair<Point, int> > vec;
    vector<int> tdo;
    
    cin >> q;
    while(q--){
	char ch;
	cin >> ch;
	if(ch == 'A'){
	    cin >> p[C].X >> p[C].Y >> p[C].Z;
	    tdo.PB(2 * C + 1);
	    C++;
	}
	else{
	    int id;
	    cin >> id;
	    --id;
	    tdo.PB(2 * id);
	}
    }
    
    fx = -1;
    
    for(int i = 0; i < C; i++){
	if(inL(center, p[i]))
	    continue;
	fx = i;	
    }
    for(int i = 0; i < C; i++){
	if(inL(center, p[i]))
	    continue;
	if(up(p[i]))
	    vec.PB({p[i], i});
	else
	    vec.PB({2 * center - p[i], i});
    }
    sort(vec.begin(), vec.end(), [](pair<Point, int>  a, pair<Point, int> b){ return ffC(center, a.F, b.F) > 0; } );
    Point lst;
    for(auto p : vec){
	if(N == 0 || ffC(center, lst, p.F) != 0){
	    N++;
	    lst = p.F;
	}
	ID[p.S] = N-1;
    }
    for(int x : tdo){
	if(x & 1)
	    add(x >> 1);
	else
	    era(x >> 1);
	cout << solve() << "\n";
    }
    return 0;
}