#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
string s, t;
int q;
int n, m;

int pss[MN];
int pst[MN];
int cnts[MN];
int cntt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;
    cin >> q;
    n=s.length(); m=t.length();

    FOR(i, 1, n){
        if(s[i-1] == 'B' || s[i-1] == 'C'){
            pss[i] = pss[i-1]+1;
            cnts[i] = 0;
        } else{
            pss[i] = pss[i-1];
            cnts[i] = cnts[i-1]+1;;
        }
    }
    FOR(i, 1, m){
        if(t[i-1] == 'B' || t[i-1] == 'C'){
            pst[i] = pst[i-1]+1;
            cntt[i] = 0;
        } else{
            pst[i] = pst[i-1];
            cntt[i] = cntt[i-1]+1;
        }
    }
    
    F0R(_, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int amts = pss[b]-pss[a-1];
        int amtt = pst[d]-pst[c-1];
        int strs = min(b-a+1, cnts[b]);
        int strt = min(d-c+1, cntt[d]);

        //cout << amts << " " << amtt << " " << strs << " " << strt << "\n";
        if(amts > amtt || ((amts-amtt)%2!=0)){
            cout << "0";
        } else if(amts == amtt){
            if((strs - strt) % 3 == 0 && strs >= strt){
                cout << "1";
            } else{
                cout << "0";
            }
        } else if(amts == 0){
            if(strs > strt){
                cout << "1";
            } else{
                cout << "0";
            }
        } else{
            if(strs >= strt){
                cout << "1";
            } else{
                cout << "0";
            }
        }

        /*if((amts-amtt)%2 == 0 && amts <= amtt && (strs-strt)%3 == 0 && strs >= strt){
            cout << "1";
        } else{
            cout << "0";
        }*/
    }

    return 0;
}