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
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
#define BAD 100000
ll n;
ll b[MN];
ll msbs[MN];
ll curins[2*MN];

ll cmsb(ll x){
    ll cnt = 0;
    while(x != 0){
        x /= 2;
        cnt++;
    }
    return cnt-1;
}

void resz(ll nt){
    ll curon = nt*2-1;
    RFOR(i, nt*2, 0){
        if(curins[i] != 0){
            curins[curon] = curins[i];
            curon -= 2;
        }
    }
    for(ll i=0; i<=nt*2; i+=2){
        curins[i] = 0;
    }

    /*F0R(i, nt*2+1){
        cout << curins[i] << " ";
    }
    cout << "\n";*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    F0R(i, n){
        cin >> b[i];
    }
    sort(b, b+n, greater<ll>());
    /*if(n == BAD){
        F0R(i, n){
            cout << b[i] << " ";
        }
        return 0;
    }*/

    F0R(i, n){
        msbs[i] = cmsb(b[i]);
        //cout << "msb of " << b[i] << " is " << msbs[i] << "\n";
    }

    ll ntsf = 0;
    ll co = 0;
    RFOR(mb, 60, 0){
        if(co == n) break;
        if(msbs[co] > mb){
            cout << "No\n";
            return 0;
        } else if(msbs[co] < mb) continue;

        /*if(n == BAD){
            cout << "on " << mb << "\n";
        }*/

        ll curxor = 0;
        F0R(i, 2*ntsf+1){
            if(curins[i] != 0){
                curxor ^= curins[i];
            } else{
                if((curxor & (1LL<<msbs[co])) == 0){
                    curins[i] = b[co];
                    curxor ^= b[co];
                    co++;

                    if(co == n || msbs[co] < mb) break;
                }
            }
        }

        ntsf = co;
        resz(ntsf);
    }
    if(co != n){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    F0R(i, n*2+1){
        if(curins[i] != 0) cout << curins[i] << " ";
    }

    return 0;
}