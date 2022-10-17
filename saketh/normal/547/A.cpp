#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

typedef long long ll;

ll M;

int seen[1000005];

pair<ll, ll> find(ll H, ll X, ll Y, ll A){
    memset(seen, 0xff, sizeof(seen));

    for(int i=0;; i++){
        if(seen[H] != -1){
            int cycle = i - seen[H];
            if(seen[A] != -1 && seen[A] + cycle < i) cycle *= -1;
            return make_pair(seen[A], cycle);
        }
        seen[H] = i;
        H = (X * H + Y) % M;
    }
} 

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ll H1, A1, X1, Y1;
    ll H2, A2, X2, Y2;

    cin >> M;
    cin >> H1 >> A1 >> X1 >> Y1;
    cin >> H2 >> A2 >> X2 >> Y2;

    pair<ll, ll> c1 = find(H1, X1, Y1, A1);
    pair<ll, ll> c2 = find(H2, X2, Y2, A2);

    if(c1.first == -1 || c2.first == -1){
        cout << -1 << endl;
        return 0;
    }

    if(c1.second < c2.second) swap(c1, c2);
    
    if(c1.second < 0 || c2.second < 0){
        int ans = -1;
        if(c1.first == c2.first) ans = c1.first;
        else if(c1.second > 0){
            if(c2.first % c1.second == c1.first % c1.second && c2.first >= c1.first)
                ans = c2.first;
        }
        cout << ans << endl;
        return 0;
    }

    ll MM = c1.second / gcd(c1.second, c2.second) * c2.second; 
    ll U = c1.first % c1.second;
    ll V = c2.first % c2.second;
    ll S = -1;

    for(ll C = U; C < MM; C += c1.second){
        if(C % c2.second == V){
            S = C;
            break;
        }
    }    

    if(S == -1){
        cout << -1 << endl;
    }
    else{
        while(S < max(c1.first, c2.first))
            S += MM;
        cout << S << endl;
    }
}