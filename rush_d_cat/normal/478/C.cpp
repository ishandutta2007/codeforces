#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> v;
LL r, g, b;

int main() 
{
    cin >> r >> g >> b; 
    LL sum = r + g + b;
    v.push_back(r), v.push_back(g), v.push_back(b);
    sort(v.begin(), v.end());

    if(2*(v[0] + v[1]) >= v[2]) {
        printf("%lld\n", sum / 3);
    } else {
        printf("%lld\n", (v[0] + v[1]));
    }

}