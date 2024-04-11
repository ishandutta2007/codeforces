#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
string s, t;
int n, m;
int zc, oc; //1ct

int lps[MN];
void getlps(){
    int len = 0;
    lps[0] = 0;

    int i=1;
    while(i < m){
        if(t[i] == t[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(len != 0){
                len = lps[len-1];
            } else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;
    n=s.length(); m=t.length();

    F0R(i, n){
        if(s[i] == '1') oc++;
        else zc++;
    }

    getlps();
    /*FOR(i, 0, m){
        cout << lps[i] << " ";
    }
    cout << "\n";*/

    if(oc == 0){
        F0R(j, n){
            cout << '0';
        }
        return 0;
    } else if(zc == 0){
        F0R(j, n){
            cout << '1';
        }
        return 0;
    }

    int cur = 0;
    F0R(i, n){
        if(t[cur] == '1') oc--;
        else zc--;

        cout << t[cur];
        cur++;
        if(cur == m){
            cur = lps[m-1];
        }

        if(oc == 0){
            FOR(j, i+1, n-1){
                cout << '0';
            }
            return 0;
        } else if(zc == 0){
            FOR(j, i+1, n-1){
                cout << '1';
            }
            return 0;
        }
    }

    return 0;
}