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

#define MN 10005
int n;
string t;
string i1, i2, i3;
string o1, o2, o3;

ll inp[MN];
ll oup[MN];

map<ll, int> mep;

string res;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> t;
    n = t.length();
    i1.resize(n);
    i2.resize(n);
    i3.resize(n);

    res.resize(n);

    F0R(i, n){
        i1[i] = 'a'+i%26;
        i2[i] = 'a'+(i/26)%26;
        i3[i] = 'a'+(i/26/26)%26;
    }

    cout << "? " << i1 << endl;
    cout.flush();
    cin >> o1;
    if(o1 == "0") exit(0);

    cout << "? " << i2 << endl;
    cout.flush();
    cin >> o2;
    if(o2 == "0") exit(0);

    cout << "? " << i3 << endl;
    cout.flush();
    cin >> o3;
    if(o3 == "0") exit(0);

    F0R(i, n){
        inp[i] = (i3[i]-'a')*26*26+(i2[i]-'a')*26+(i1[i]-'a');
        oup[i] = (o3[i]-'a')*26*26+(o2[i]-'a')*26+(o1[i]-'a');
        //cout << inp[i] << " " << oup[i] << "\n";
        mep.insert(mp(inp[i], i));
    }
    F0R(i, n){
        int j = mep[oup[i]];
        res[j] = t[i];
    }

    cout << "! " << res << "\n";
    cout.flush();

    return 0;
}