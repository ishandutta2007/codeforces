#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define MAX_N 105

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
double prob[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    F0R(i, N){
        cin >> prob[i];
    }

    sort(prob, prob+N, greater<double>());
    /*F0R(i, N){
        cout << prob[i] << " ";
    }
    cout << "\n";*/

    double p1 = 1, p2 = 0;
    int i=0;
    while(p1 > p2 && i < N){
        p2 = p1*prob[i]+p2*(1-prob[i]);
        p1 = p1*(1-prob[i]);
        //cout << "p2 is now " << p2 << " and p1 is " << p1 << "\n";
        i++;
    }

    cout << setprecision(9) << p2 << "\n";

    return 0;
}