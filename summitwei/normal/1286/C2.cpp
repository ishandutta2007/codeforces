#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n;
vector<string> c1;
vector<string> c2;
vector<string> c3;
vector<string> almost;
int app[MN][30];
string p1;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    
    if(n <= 3){
        FOR(i, 1, n){
            cout << "? " << i << " " << i << endl;
            cout.flush();
            char resp;
            cin >> resp;
            p1.pb(resp);
        }
        cout << "! " << p1 << endl;
        cout.flush();
        return 0;
    }
    
    int mid = (n+1)/2;
    cout << "? 1 " << mid << endl;
    cout.flush();
    F0R(_, (mid)*(mid+1)/2){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        //cout << s << "\n";
        c1.pb(s);
    }
    cout << "? 2 " << mid << endl;
    cout.flush();
    F0R(_, mid*(mid-1)/2){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        c2.pb(s);
    }
    multiset<string> a;
    for(auto u : c1){
        a.insert(u);
    }
    for(auto u : c2){
        a.erase(a.find(u));
    }

    for(auto u : a){
        int len = u.length();
        F0R(i, len){
            ++app[len][u[i]-'a'];
        }
    }
    p1.resize(n+1);
    //cout << "! ";
    FOR(i, 1, mid){
        int c;
        F0R(j, 26){
            if(app[i][j] > app[i-1][j]){
                c = j;
                break;
            }
        }
        p1[i] = 'a'+c;
    }
    //cout.flush();

    cout << "? 1 " << n << endl;
    cout.flush();
    F0R(_, (n)*(n+1)/2){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        //cout << s << "\n";
        c3.pb(s);
    }

    a.clear();
    for(auto u : c3){
        a.insert(u);
    }
    for(auto u : c1){
        a.erase(a.find(u));
    }

    memset(app, 0, sizeof app);

    for(auto u : a){
        int len = u.length();
        F0R(i, len){
            ++app[len][u[i]-'a'];
        }
    }
    int o=2;
    RFOR(i, n, mid+1){
        RFOR(j, mid, mid-(o-2)){
            app[o][p1[j]-'a'] += (mid-j+1);
        }
        RFOR(j, n, i+1){
            app[o][p1[j]-'a'] += (j-i+1);
        }

        int c;
        F0R(j, 26){
            if(app[o][j] % o != 0){
                c = j;
                break;
            }
        }
        p1[i] = 'a'+c;
        ++o;
    }
    cout << "! ";
    FOR(i, 1, n){
        cout << p1[i];
    }
    cout << endl;
    cout.flush();

    return 0;
}