#include <bits/stdc++.h>
using namespace std;

int main() {
    int a , b , c , d , e , f , g , h , i , j;

    cin >> a >> b >> c >> d;
    e = a ^  b;
    f = c |  d;
    g = b & c;
    h = a ^  d;
    i = e &  f;
    j = g |  h;
    cout << (i ^ j) << endl;
}