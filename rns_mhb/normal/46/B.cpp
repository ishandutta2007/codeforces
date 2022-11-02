#include<bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;
    for(int i = 0; i < 5; i ++) {
        int x;
        cin >> x;
        while(x --) v.push_back(i);
    }
    int q;
    scanf("%d", &q);
    string S[5] = {"S", "M", "L", "XL", "XXL"};
    while(q --) {
        string s;
        cin >> s;
        int m;
        for(int i = 0; i < 5; i ++) if(s == S[i]) m = i;
        sort(v.begin(), v.end(), [&](int i, int j) {
            int ii = abs(m-i), jj = abs(m-j);
            if(ii == jj) return i < j;
            return ii > jj;
        });
        cout << S[v.back()] << endl;
        v.pop_back();
    }
}