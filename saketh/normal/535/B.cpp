#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> lucky;

void gen(long long val){
    if(val > 1000000000) return;
    if(val) lucky.push_back(val);
    gen(10 * val + 4);
    gen(10 * val + 7);
}

int main(){
    gen(0);
    sort(lucky.begin(), lucky.end());

    cin >> N;
    cout << (lower_bound(lucky.begin(), lucky.end(), N) - lucky.begin()) + 1 << endl;
}