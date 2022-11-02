#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
//#define INF 0x3f3f3f3f
#define INF 1000000000LL
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
ll a[3], b[3];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    cout << "First" << endl;
    cout.flush();
    cout << INF << endl;
    cout.flush();
    int x;
    cin >> x;
    a[x-1] += INF;
    //ll b[3];
    memcpy(b, a, sizeof a);
    sort(b, b+3);
    ll d1=b[1]-b[0], d2=b[2]-b[1];
    ll dif=d1+2*d2;
    cout << dif << endl;
    cout.flush();
    cin >> x;
    if(x==0) exit(0);
    a[x-1] += dif;
    memcpy(b, a, sizeof a);
    sort(b, b+3);
    d1=b[1]-b[0]; d2=b[2]-b[1];
    cout << d1 << endl;
    cout.flush();
    cin >> x;
    //assert(x==0);
    exit(0);
    
    return 0;
}