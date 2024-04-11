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

bool que(int x, int y){ //true if x >= y
    cout << "? " << x << " " << y << endl;
    cout.flush();
    char c;
    cin >> c;
    if(c == 'e'){
        exit(0);
    }
    
    return c=='x';
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    string s;
    cin >> s;
    while(s == "start"){
        int p = 1;
        while(!que(p-1, 2*p-1)) p*=2;
        
        int res = p;
        p /= 2;
        while(p >= 1){
            if(que(res+p-1, res-1)) res += p;
            p /= 2;
        }
        
        cout << "! " << res << endl;
        cout.flush();
        
        cin >> s;
    }
    
    return 0;
}