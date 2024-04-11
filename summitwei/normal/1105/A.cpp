#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000009
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
int l[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> l[i];
    }

    int mns = INF;
    int mni = 0;
    FOR(i, 1, 1000){
        int cs = 0;
        F0R(j, n){
            if(l[j] > i) cs += (l[j]-(i+1));
            else if(l[j] < i) cs += (i-1)-l[j];
        }

        if(cs < mns){
            mns = cs;
            mni = i;
        }
    }

    cout << mni << " " << mns << "\n";

    return 0;
}