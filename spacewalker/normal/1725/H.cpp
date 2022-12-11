#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
void soln(int Z, string s) {
    cout<<Z<<"\n"<<s<<"\n";exit(0);
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(3);
    rep(i, 0, n) {
        int x;cin>>x;
        arr[x%3].push_back(i);
    }
    string str;
    rep(i, 0, n) {
        str.push_back('0');
    }
    if (arr[0].size() <= n/2) {
        for (auto x: arr[0]) {
            str[x] = '1';
        }
        int rem = n/2 - arr[0].size();
        rep(i, 0, n) {
            if (str[i] == '0' && rem > 0) {
                rem--;
                str[i] = '1';
            }
        }
        soln(0, str);
    }
    rep(i, 0, n/2) {
        str[arr[0][i]] = '1';
    }
    soln(2, str);
}