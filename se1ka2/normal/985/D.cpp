#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull sum(ull i, ull h){
    if(i <= h) return i * (i + 1) / 2;
    else return i * (i + 1) / 2 - (i - h + (i - h) % 2) * ((i - h + 2) / 2) / 2;
}

int main()
{
    ull n, h;
    cin >> n >> h;
    ull left = 0, right = 2000000003;
    while(right - left > 1){
        ull mid = (right + left) / 2;
        if(sum(mid, h) >= n) right = mid;
        else left = mid;
    }
    cout << right << endl;
}