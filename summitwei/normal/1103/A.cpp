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

#define MN 40005
int vcnt = 0;
int hcnt = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    F0R(i, s.length()){
        if(s[i] == '0'){
            cout << "1 " << vcnt+1 << "\n";
            vcnt = (vcnt+1)%4;
        } else{
            cout << "4 " << hcnt+1 << "\n";
            hcnt = (hcnt+2)%4;
        }
    }
    
    return 0;
}