// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    double a, b, m, vx, vy, vz;
    cin >> a >> b >> m >> vx >> vy >> vz;
    assert(vy < 0);
    double t = m / (-vy);
    double X = (a/2) + t * vx;
    double Y = t * vz;

    while(X < 0)
	X+= 2*a;
    while(X >= 2*a)
	X-= 2*a;
    while(Y < 0)
	Y+= 2*b;
    while(Y >= 2*b)
	Y-= 2*b;
    if(X > a)
	X = 2*a - X;
    if(Y > b)
	Y = 2*b - Y;
    return cout << setprecision(10) << fixed << X << " " << Y << "\n", 0;
}