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

#define MN 500005
#define ML 35
int q;
multiset<int> blah[ML];
ll sums[ML];

void ins(int x){
    int lg = (int)log2(EPSILON+x);
    blah[lg].insert(x);
    sums[lg] += x;
}
void del(int x){
    int lg = (int)log2(EPSILON+x);
    blah[lg].erase(blah[lg].find(x));
    sums[lg] -= x;
}

int cb(){
    int cnt = 0;
    ll sm = 0;
    F0R(i, ML){
        if((*blah[i].begin()) > 2*sm){
            cnt++;
        }
        sm += sums[i];
        if(sm > INF) break;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;

    int cur = 0;
    F0R(_, q){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            ins(x);
            cur++;
        } else{
            del(x);
            cur--;
        }

        cout << cur-cb() << "\n";
    }

    return 0;
}