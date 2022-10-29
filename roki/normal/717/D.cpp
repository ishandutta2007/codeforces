#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, m;
const int N = 128;

typedef vector<vector<ld> > matrix;

matrix mul(matrix a, matrix b) {
    matrix c = a;
    forn (i, N)
        forn (j, N)
            c[i][j] = 0;
    forn (i, N)
        forn (j, N)
            forn (k, N) {
                c[i][j] += a[i][k] * b[k][j]; 
            }
    return c;
}

ld a[N];
       
bool read() {

    cin >> n >> m;
    m++;
    forn (i, m)
        cin >> a[i];
    return true;
}
              
matrix bp(matrix a, int d) {
    if (d == 1)
        return a;
    if (d & 1)
        return mul(a, bp(a, d - 1));
    return bp(mul(a, a), d / 2);
}

void solve() {
    matrix mat;
    mat.resize(N);
    forn (i, N)
        mat[i].resize(N);
    forn (i, N)
        forn (j, m)
            mat[i][i ^ j] += a[j];
    
    matrix ans = bp(mat, n);
    mat = ans;
    forn (i, 8) {
        forn (j, 8)
            cerr << mat[i][j] << ' ';
        cerr << endl;
    }
    ld x = 0;
    for (int i = 1; i < N; ++i)
        x += mat[0][i];
    cout << x << endl;
}

int main() {
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
    
    read();
	solve();     
    

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}