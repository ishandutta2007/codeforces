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

#define MN 100005
int que(int fr){ //bitmask, return size cuz we don't need anything else i think
    cout << "next";
    F0R(i, 10){
        if((1<<i) & fr){
            cout << " " << i;
        }
    }
    cout << endl;
    cout.flush();

    int k;
    cin >> k;
    string s;
    F0R(i, k){
        cin >> s;
    }

    return k;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int cnt;
    int steps = 0;
    do{
        que(3);
        cnt = que(1);
        steps++;
    } while(cnt != 2);

    do{
        cnt = que(1023);
    } while(cnt != 1);

    cout << "done" << endl;
    cout.flush();
    
    return 0;
}