#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define PI 3.14159265358979323846264338327950288
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define INF 1000000000
#define MOD 1000000009
#define EPSILON 0.00001
#define MAX_N 105

int n;

double dists[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if(n == 3 || n == 4){
        cout << "No solution\n";
        return 0;
    }

    double angle = 2*PI/((double)n);

    F0R(i, n/2){
        dists[i] = (i)+200;
    }
    FOR(i, n/2, n-1){
        //dists[i] = 0.1*i+9.9;
        if(i % 2 == 0){
            dists[i] = (i-(n/2))+199.7;
        } else{
            dists[i] = (i-(n/2))+200.3;
        }
    }

    /*F0R(i, n-1){
        cout << dists[i] << " ";
    }
    cout << "\n";*/

    //cout << angle << "\n";

    cout << "0 0\n";
    pdd coor = mp(0, 0);

    double len = dists[0];
    double theta = angle; //last line is horiz so ez
    FOR(i, 1, n-2){
        coor.f += (len*cos(theta));
        coor.s += (len*sin(theta));

        cout << coor.f << " " << coor.s << "\n";

        theta += angle;
        len = dists[i];
    }

    double difY = -coor.s;
    double tangent = tan(theta);

    //cout << tangent << "\n";

    double difX = difY/tangent; //math is actual cancer tbh
    cout << coor.f+difX << " " << 0 << "\n";

    return 0;
}