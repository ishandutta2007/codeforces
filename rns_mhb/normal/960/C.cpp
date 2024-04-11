#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, d;
    cin >> x >> d;
    long long v = 1;
    vector <long long> ans;
    while(x) {
        int y = 1, z = 1;
        while(2*y+1 <= x) y = 2*y+1, z ++;
        while(z --) ans.push_back(v);
        v += d;
        x -= y;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
    cout << endl;
}