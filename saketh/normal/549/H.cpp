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

typedef long double ld;
ld A, B, C, D;

pair<ld, ld> prod_range(ld a, ld b, ld c, ld d){
    ld x = min(min(a*c, a*d), min(b*c, b*d));
    ld y = max(max(a*c, a*d), max(b*c, b*d));
    return {x, y};
}

pair<ld, ld> prod_range(pair<ld, ld> r1, pair<ld, ld> r2){
    return prod_range(r1.first, r1.second, r2.first, r2.second);
}

pair<ld, ld> make_range(ld init, ld targ_abs){
    ld end1 = init - targ_abs;
    ld end2 = init + targ_abs;
    return {min(end1, end2), max(end1, end2)};
}

bool intersect(pair<ld, ld> a, pair<ld, ld> b){
    return max(a.first, b.first) <= min(a.second, b.second);
}

bool poss(ld norm){
    pair<ld, ld> r1 = make_range(A, norm);
    pair<ld, ld> r2 = make_range(B, norm);
    pair<ld, ld> r3 = make_range(C, norm);
    pair<ld, ld> r4 = make_range(D, norm);
    pair<ld, ld> p1 = prod_range(r1, r4), p2 = prod_range(r2, r3);
    return intersect(p1, p2); 
}

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}

int main(){
	setup();
    cin >> A >> B >> C >> D;
    
    ld hi = max(max(abs(A), abs(B)), max(abs(C), abs(D)));
    ld lo = 0;

    while((hi - lo)/hi > 1e-13){
        ld mi = (lo + hi) / 2;
        if(poss(mi)) hi = mi;
        else lo = mi;
    }
    cout.precision(20);
    cout << (lo+hi)/2 << endl;
}