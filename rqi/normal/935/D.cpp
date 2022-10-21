#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

ll MOD = 1000000007;
/*
CUML SUM
DFS BFS BIN SEARCH
STRUCTS
TWOPOINT
GREEDY
Data Structures
Basic 1D Range Queries
Graphs
Shortest Path
Topological Sort
Strings
Hashing
Trees
MST
Dynamic Programming
Intro
*/
 
// To find GCD of a and b
ll gcd(ll a, ll b);
 
// To compute x raised to power y under modulo m
ll power(ll x, ll y, ll m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m)
{
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
    return power(a, m-2, m);
    
}
 
// To compute x^y under modulo m
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
 
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

class Fraction {
    

    public:
        long long numerator, denominator;

        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(long long n, long long d) {
            if (d==0) {
                cerr << "Denominator may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                ll sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                long long tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }

        operator ll() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp((lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator) % MOD,
                (lhs.denominator*rhs.denominator) % MOD);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp((lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator) % MOD,
                (lhs.denominator*rhs.denominator) % MOD);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp((lhs.numerator*rhs.numerator) % MOD,
               (lhs.denominator*rhs.denominator)% MOD) ;
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp((lhs.numerator*rhs.numerator) % MOD,
               (lhs.denominator*rhs.denominator) % MOD);
    lhs = tmp;
    return lhs;
}

Fraction operator*(ll lhs, const Fraction& rhs) {
    Fraction tmp((lhs*rhs.numerator)% MOD,(rhs.denominator) % MOD);
    return tmp;
}

Fraction operator*(const Fraction& rhs, ll lhs) {
    Fraction tmp((lhs*rhs.numerator) % MOD,(rhs.denominator) % MOD);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp((lhs.numerator*rhs.denominator) % MOD,
                 (lhs.denominator*rhs.numerator) % MOD);
    return tmp;
}

std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator % MOD;
    } else {
        strm << a.numerator % MOD << "/" << a.denominator % MOD;
    }
    return strm;
}

ll a[100005];
ll b[100005];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
	    cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
	    cin >> b[i];
	}
	Fraction ans(0, 1);
	Fraction factor(1, 1);
	for(ll i = 0; i < n; i++){
	    if(a[i] == 0 && b[i] == 0){
	        Fraction c((m*(m-1))/2, m*m);
	        ans = ans + factor*c;
	        Fraction d(1, m);
	        ans.denominator = ans.denominator % MOD;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	        factor*=d;
	    }
	    else if(a[i] == 0 && b[i] != 0){
	        Fraction c((m-b[i]), m);
	        ans = ans+factor*c;
	        Fraction d(1, m);
	        ans.denominator = ans.denominator % MOD;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	        factor*=d;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	    }
	    else if(a[i] != 0 && b[i] == 0){
	        Fraction c((a[i]-1), m);
	        ans = ans+factor*c;
	        Fraction d(1, m);
	        ans.denominator = ans.denominator % MOD;
	        factor*=d;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	    }
	    else if(a[i] > b[i]){
	        ans = ans+factor;
	        factor = Fraction(0, 1);
	        ans.denominator = ans.denominator % MOD;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	        break;
	        
	    }
	    else if(a[i] < b[i]){
	        factor= Fraction(0, 1);
	        ans.denominator = ans.denominator % MOD;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	        break;
	    }
	    else if(a[i] == b[i]){
	        ans.denominator = ans.denominator % MOD;
	        factor.denominator = factor.denominator % MOD;
	        factor.numerator = factor.numerator % MOD;
	        ans.numerator = ans.numerator % MOD;
	    }
	}
	
	        
	ll P = (ans.numerator+MOD) % MOD;
	ll Q = (ans.denominator+MOD) % MOD;
	P = P % MOD;
	ll Qinv = modInverse(Q, MOD) % MOD;
	cout << (P*Qinv+MOD) % MOD;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!