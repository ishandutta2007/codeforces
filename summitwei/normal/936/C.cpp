#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n;
string s, t;
int a[MN];
int perm[MN];

vi ree;

int ot[MN];
void op(int x){
    if(x <= 0) return;
    ree.pb(x);
    F0R(i, x){
        ot[i] = perm[n-1-i];
    }
    FOR(i, x, n-1){
        ot[i] = perm[i-x];
    }
    memcpy(perm, ot, sizeof perm);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s >> t;
    F0R(i, n){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }
    F0R(i, 26){
        if(a[i] != 0){
            cout << "-1\n";
            return 0;
        }
    }
    memset(perm, -1, sizeof perm);
    F0R(i, n){
        F0R(j, n){
            if(perm[j] == -1 && s[j] == t[i]){
                perm[j] = i;
                //cout << j << " paired with " << i << "\n";
                break;
            }
        }
    }
    /*F0R(i, n) cout << perm[i] << " ";
    cout << "\n";*/
    int loc = find(perm, perm+n, 0)-perm;
    op(n-loc-1);
    /*F0R(i, n) cout << perm[i] << " ";
    cout << "\n";*/
    for(int i=1; i<n-1; i+=2){
        loc = find(perm, perm+n, i)-perm;
        op(n-loc-1);
        op(1);
        //F0R(i, n) cout << perm[i] << " ";
        //cout << "\n";
        loc = find(perm, perm+n, i+1)-perm;
        op(n-loc);
        //F0R(i, n) cout << perm[i] << " ";
        //cout << "\n";
        loc = find(perm, perm+n, i+1)-perm;
        op(n-loc);
        //F0R(i, n) cout << perm[i] << " ";
        //cout << "\n";
        loc = find(perm, perm+n, i+1)-perm;
        op(n-loc-1);
        //F0R(i, n) cout << perm[i] << " ";
        //cout << "\n";
    }
    if(n % 2 == 0){
        op(n-1); op(1); op(n);
        //F0R(i, n) cout << perm[i] << " ";
        //cout << "\n";
    }

    cout << ree.size() << "\n";
    for(auto u : ree) cout << u << " ";
    cout << "\n";

    return 0;
}