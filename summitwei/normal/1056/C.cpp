#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n, m;
int powers[2*MAX_N];
pii pairs[MAX_N];
int pairedTo[2*MAX_N];
int t;

vi unpaired;
bool used[MAX_N*2];

bool comp(int a, int b){
    return powers[a] >= powers[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i, 1, 2*n){
        cin >> powers[i];
    }
    F0R(i, m){
        cin >> pairs[i].f >> pairs[i].s;
        pairedTo[pairs[i].f] = pairs[i].s;
        pairedTo[pairs[i].s] = pairs[i].f;
    }
    cin >> t;

    FOR(i, 1, 2*n){
        if(pairedTo[i] == 0){
            unpaired.pb(i);
        }
    }

    sort(unpaired.begin(), unpaired.end(), comp);
    memset(used, false, sizeof used);

    if(t == 1){
        F0R(i, m){
            int blah;
            if(powers[pairs[i].f] < powers[pairs[i].s]){
                cout << pairs[i].s << "\n";
            } else{
                cout << pairs[i].f << "\n";
            }
            cout.flush();
            cin >> blah;
            if(blah == -1) exit(0);
        }

        F0R(i, n-m){
            int unused;
            for(auto j : unpaired){
                if(!used[j]){
                    unused = j;
                    break;
                }
            }

            cout << unused << "\n";
            cout.flush();
            used[unused] = true;
            int blah;
            cin >> blah;
            if(blah == -1) exit(0);
            used[blah] = true;
        }
    } else{
        int cnt = 1;

        int blah;
        cin >> blah;
        if(blah == -1) exit(0);

        while(pairedTo[blah] != 0){
            used[blah] = true;
            used[pairedTo[blah]] = true;

            cout << pairedTo[blah] << "\n";
            cout.flush();
            if(cnt == n) return 0;
            cin >> blah;
            if(blah == -1) exit(0);
            cnt++;
        }

        used[blah] = true;

        F0R(i, m){
            if(!used[pairs[i].f]){
                if(powers[pairs[i].f] < powers[pairs[i].s]){
                    cout << pairs[i].s << "\n";
                } else{
                    cout << pairs[i].f << "\n";
                }
                cout.flush();
                cin >> blah;
                if(blah == -1) exit(0);
                cnt++;
            }
        }

        F0R(i, n-m){
            int unused = -1;
            for(auto j : unpaired){
                if(!used[j]){
                    unused = j;
                    break;
                }
            }
            if(unused == -1){
                return 0;
            }

            cout << unused << "\n";
            cout.flush();
            if(cnt == n) return 0;
            used[unused] = true;
            int blah;
            cin >> blah;
            if(blah == -1) exit(0);
            used[blah] = true;
            cnt++;
        }
    }
    
    return 0;
}