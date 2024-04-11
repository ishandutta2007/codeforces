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

#define MN 50005
int n;
pair<pii, pii> o[MN];
pair<pii, pii> a[MN];
vi hmm;

int lay(int x, int y){
    if(o[x].f.f == o[y].f.f){
        if(o[x].f.s == o[y].f.s){
            if(o[x].s.f == o[y].s.f){
                return 3;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i].f.f >> a[i].f.s >> a[i].s.f;
        a[i].s.s = i;
        o[i] = a[i];
    }
    sort(a+1, a+n+1);
    
    FOR(i, 1, n){
        int x = a[i].s.s;

        int lst = hmm.size()-1;
        while(lst > 0 && lay(hmm[lst-1], hmm[lst]) >= lay(hmm[lst], x)){
            cout << hmm[lst-1] << " " << hmm[lst] << "\n";
            hmm.pop_back();
            hmm.pop_back();
            lst -= 2;
        }

        hmm.pb(a[i].s.s);
    }
    while(!hmm.empty()){
        cout << hmm[hmm.size()-2] << " " << hmm[hmm.size()-1] << "\n";
        hmm.pop_back();
        hmm.pop_back();
    }
    
    return 0;
}