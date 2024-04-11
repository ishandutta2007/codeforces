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
#define INF 0x3f3f3f3f
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
int n;
int k, bst;
vi hmm;
bool on[MN];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    cin >> n;
    if(n <= 3){
        cout << 0 << endl;
        cout.flush();
        return 0;
    }
    FOR(i, 2, n){
        //blocks of i-1 and then a bad
        //number of good is at most (k-1/k) since capped by (k-1)*bad
        int bad = (n+i-1)/i;
        int good = n-bad-(i-1);
        //cout << "trying " << i << " " << good << "\n";
        if(good > bst){
            k = i;
            bst = good;
        }
    }
    FOR(i, 1, n){
        if(i%k != 0){
            hmm.pb(i);
        }
    }
    int cnt = 0;
    while(cnt < bst){
        cout << k;
        F0R(_, k){
            int aah = hmm[hmm.size()-1];
            cout << " " << aah;
            hmm.pop_back();
            on[aah] = true;
            ++cnt;
        }
        cout << endl;
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1){
            exit(0);
        }
        F0R(_, k){
            if(on[resp]){
                on[resp] = false;
                hmm.pb(resp);
                --cnt;
            }
            ++resp;
            if(resp == n+1) resp = 1;
        }
    }

    cout << 0 << endl;
    cout.flush();

    return 0;
}