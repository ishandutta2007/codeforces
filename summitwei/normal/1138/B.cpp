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

#define MN 5005
int n;
int a[MN];
int cnt[4];
int amts[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        char c;
        cin >> c;
        if(c == '1') a[i]++;
    }
    F0R(i, n){
        char c;
        cin >> c;
        if(c == '1') a[i] += 2;
    }
    F0R(i, n){
        cnt[a[i]]++;
    }
    //F0R(i, 4) cout << cnt[i] << " ";
    //cout << "\n";

    bool ok = false;
    F0R(i, cnt[3]+1){
        //number of boths on the first
        //clown = 1, 3
        //acro = 2, 3
        F0R(j, cnt[1]+1){
            //# of only clowns on the first
            if(i+j>n/2) continue;
            int amt = i+j;
            int amt2 = cnt[3]-i;
            int acros = amt-amt2;
            if(acros < 0 || acros+amt2>n/2) continue;
            amts[3] = i; amts[1] = j; amts[2] = cnt[2]-acros; amts[0] = n/2-amts[1]-amts[2]-amts[3];
            if(amts[0] <= cnt[0] && amts[2] <= cnt[2] && amts[0] >= 0 && amts[2] >= 0){
                //cout << "found " << i << " " << j << "\n";
                //F0R(i, 4) cout << amts[i] << " ";
                //cout << "\n";
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    if(!ok){
        cout << "-1\n";
    } else{
        F0R(i, n){
            if(amts[a[i]] != 0){
                cout << i+1 << " ";
                --amts[a[i]];
            }
        }
    }

    return 0;
}