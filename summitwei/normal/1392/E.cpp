#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 30
int n;
ll a[MN][MN];
int q;
ll k;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    F0R(i, n){
        F0R(j, n){
            if(i%2) a[i][j] = 1LL<<(i+j);
        }
        /*FOR(j, 1, i){
            a[j][i-j] = (j%2)?(1LL<<(2*i-1)):(1LL<<(2*i));
        }*/
    }
    F0R(i, n){
        F0R(j, n){
            cout << a[i][j] << " ";
        }
        cout << endl;
        cout.flush();
    }
    cin >> q;
    F0R(i, q){
        cin >> k;
        int cx = 0, cy = 0;
        cout << cx+1 << " " << cy+1 << endl;
        cout.flush();
        while(cx!=n-1||cy!=n-1){
            /*if(a[cx][cy+1]&k != 0){
                ++cy;
            } else{
                ++cx;
            }*/
            if(cx==n-1) ++cy;
            else if(cy==n-1) ++cx;
            else{
                if(a[cx][cy+1] != 0){
                    if(k&a[cx][cy+1]) ++cy;
                    else ++cx;
                } else{
                    if(k&a[cx+1][cy]) ++cx;
                    else ++cy;
                }
            }
            cout << cx+1 << " " << cy+1 << endl;
            cout.flush();
        }
    }

    return 0;
}