#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int main() {
    int ans;
    vector<int> v;
    cin >> ans;
    int k, l = 1100;
    if((ans + l) % 2)
        k = 1;
    else
        k = 0;
    int s = (ans + k + l)/2 + 1;
    v.push_back(0);
    v.push_back(-1);
    while(s > 0) {
        int d = min(s, MAX);
        s -= d;
        v.push_back(d);
    }
    while(v.size() < l + 2)
        v.push_back(0);
    if(k == 1)
        v.push_back(0);
    cout << v.size() << endl;
    for(auto x : v)
        cout << x << " ";
    cout << endl;
}