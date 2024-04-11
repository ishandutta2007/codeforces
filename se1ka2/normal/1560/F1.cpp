#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void all(int a, int b, int k, int x, vector<int> &v){
    if(k == 10) return;
    v.push_back(x);
    all(a, b, k + 1, x * 10 + a, v);
    all(a, b, k + 1, x * 10 + b, v);
}

int main()
{
    int t;
    cin >> t;
    vector<int> v[3];
    for(int i = 0; i < 10; i++){
        all(i, i, 0, 0, v[1]);
        for(int j = i + 1; j < 10; j++) all(i, j, 0, 0, v[2]);
    }
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == 1000000000){
            if(k == 1) cout << 1111111111 << endl;
            else cout << 1000000000 << endl;
        }
        else cout << *lower_bound(v[k].begin(), v[k].end(), n) << endl;
    }
}