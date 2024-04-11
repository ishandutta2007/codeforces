#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct point{
    int x, y;
    point(int a=0, int b = 0){x = a; y = b;}
};
struct vc{
   int x, y;
    vc(int a=0, int b = 0){x = a; y = b;}
    vc(point a, point b){x = b.x - a.x; y = b.y - a.y;}
};
int vect(vc a, vc b){
    return a.x * b.y - a.y * b.x;
}
vector<point> A, B;
set<pair<int, int> > t;
map<pair<int, int>, int> tg;
vector<int>minuss(2001, 0);
int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
//    n = 2000;
    A.resize(n);
    for(int i = 0; i < n; ++i){
//        i.x = rand() % 200 - 100;
//        i.y = rand() % 200  - 100;
     cin >> A[i].x >> A[i].y;
    }
    ll ans = (n * (n - 1) * (n - 2)) / 6;
    for(int i = 0; i < n; ++i){
        t.clear();
        tg.clear();
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            int aa = (A[j].x - A[i].x), bb = (A[j].y - A[i].y);
            int a = aa / __gcd(aa, bb);
            int b = bb / __gcd(aa, bb);
            t.insert(make_pair(a, b));
            ++tg[make_pair(a, b)];
        }
        for(auto j: t){
            if(tg[j] > 1){
                ++minuss[tg[j]];
            }
        }
    }
    for(int i = 0; i <= 2000; ++i){
        if(minuss[i]){
//            cout << i << ' ' << minuss[i] << ' ';
            ans -= (minuss[i] / (i + 1)) * ((i * (i - 1) * (i + 1))/6);
        }
    }
    cout << ans;
    return 0;
}