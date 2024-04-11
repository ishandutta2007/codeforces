#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int la, lb, ta, ra, rb, tb;
int g;

void swap(int &a, int &b){
    int tmp = a; a = b, b = tmp;
}

int get_now(){
    return max(0, min(ra, rb) - max(la, lb) + 1);
}

int main(){
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    g = __gcd(ta, tb);

    if(la == lb) return !printf("%d", min(ra - la + 1, rb - lb + 1));

    if(la > lb){
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }

    int step = (lb - la) / g;

//    cout << "step = " << step << endl;

    lb -= step * g;
    rb -= step * g;

    int res = get_now();

    lb -= g;
    rb -= g;

    res = max(res, get_now());

    cout << res << endl;




}