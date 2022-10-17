#include <iostream>
#include <algorithm>
using namespace std;

long long x1, y1, x2, y2;
long long a, b;

pair<int, int> c23(long long v){
    int c2 = 0, c3 = 0;
    for(; (v%2)==0; v/=2) c2++;
    for(; (v%3)==0; v/=3) c3++;
    return make_pair(c2, c3);
}

long long div(long long v, pair<int, int> c){
    for(int i=0; i<c.first; i++) v/=2;
    for(int i=0; i<c.second; i++) v/=3;
    return v;
}

void cons(long long x, long long y, pair<int, int> c){
    pair<int, int> b = c23(x * y); 

    for(; b.second > c.second; b.second--)
        if(x%3 == 0) x/=3, x*= 2, b.first++;
        else y/=3, y *= 2, b.first++;
    for(; b.first > c.first; b.first--)
        if(x%2 == 0) x/=2; else y/=2;

    cout << x << " " << y << endl;
}

int main(){
    cin >> x1 >> y1;
    a = x1 * y1;
    
    cin >> x2 >> y2;
    b = x2 * y2;

    pair<int, int> ac = c23(a), bc = c23(b);
    if(div(a, ac) != div(b, bc)){ cout << -1 << endl; return 0; }

    int ans = abs(ac.second - bc.second);
    if(ac.second > bc.second){
        ac.first += ac.second - bc.second;
        ac.second = bc.second;
    }
    else{
        bc.first += bc.second - ac.second;
        bc.second = ac.second;
    }

    cout << ans + max(ac.first, bc.first) - min(ac.first, bc.first) << endl;
    ac.first = min(ac.first, bc.first);
    cons(x1, y1, ac);
    cons(x2, y2, ac);
    return 0;    
}