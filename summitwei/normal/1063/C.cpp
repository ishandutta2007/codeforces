#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
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

#define MN 35
int n;
string res;
int l, r;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    cout << "1 0" << endl;
    cin >> res;

    l = 0; r = INF;

    F0R(i, n-1){
        int mid = (l+r)/2;
        cout << "1 " << mid << endl;
        string resp;
        cin >> resp;
        if(resp == res){
            l = mid;
        } else{
            r = mid;
        }
    }

    cout << "2 " << l << " 0 " << r << endl;

    return 0;
}