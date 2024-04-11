#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
#define MB 7005
int n, q;
string str;
int sieve[MB];
bool isSF[MB];
bitset<MB> s[MN];
bitset<MB> facs[MB];
bitset<MB> sf[MB];
bitset<MB> resp;

bool checkSF(int x){
    while(x > 1){
        int bf = sieve[x];
        //if(x <= 10) cout << "largest factor of " << x << " is " << bf << "\n";
        x /= bf;
        if(x % bf == 0) return false;
    }

    //if(x <= 10) cout << x << " is square free\n";
    return true;
}

void genFacs(){
    FOR(i, 1, 7000){
        if(sieve[i] <= 1) sieve[i] = i;
        for(int j=i; j<=7000; j+=i){
            facs[j][i] = true;
            if(sieve[i] == i){
                sieve[j] = i;
            }
        }
    }
}
void genSF(){
    FOR(i, 1, 7000){
        //cout << "checking " << i << "\n";
        if(checkSF(i)) isSF[i] = true;
    }
    //cout << "hmm?\n";
    FOR(i, 1, 7000){
        for(int j=1; j*i<=7000; j++){
            if(isSF[j]){
                sf[i][i*j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cout << "hmm\n";
    genFacs();
    //cout << "HMM\n";
    genSF();
    //cout << "HMMMMMMMMMMMMMMMMMMMMM\n";

    cin >> n >> q;

    F0R(asdf, q){
        int t;
        cin >> t;

        if(t == 1){
            int x, v;
            cin >> x >> v;
            s[x] = (s[x]&facs[0])|facs[v];
        } else if(t == 2){
            int x, y, z;
            cin >> x >> y >> z;
            s[x] = s[y] ^ s[z];
        } else if(t == 3){
            int x, y, z;
            cin >> x >> y >> z;
            s[x] = s[y] & s[z];
        } else{
            int x, v;
            cin >> x >> v;

            /*bool res = false;
            for(int i=v; i<=7000; i+=v){
                if(s[x][v]){
                    res = !res;
                }
            }

            //cout << res;
            str += ((int)res + '0');*/
            resp = s[x] & sf[v];
            str += ('0'+resp.count()%2);
            //cout << resp.count()%2 << "\n";
        }

        /*cout << "i=" << asdf+1 << "\n";
        FOR(i, 1, n){
            cout << i << ": ";
            FOR(j, 1, 6){
                if(s[i][j]) cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/
    }

    cout << str << "\n";

    return 0;
}