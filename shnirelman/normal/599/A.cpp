#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    if(d1 > d2)swap(d1, d2);

    cout << d1 + min(d3, d1 + d2) + min(d2, d3 + d1);
}