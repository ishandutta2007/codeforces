#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define PI 3.14159265358979
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r;
    double a = 2*sin(PI/(double(n)));

    cout << fixed << setprecision(8) << a*r/(2-a) << "\n";

    return 0;
}