#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;

int n,x,y;
string s;
vector<int> num;
int cnt[2];

int main(){
    cin >> n >> x >> y;
    getchar();
    getline(cin, s);
    for(char c : s){
        if(num.empty() || (c - '0') != num[num.size()-1]) num.push_back(c-'0'), cnt[c-'0']++;
    }
    ll res = 1LL * cnt[0] * y;
    if(cnt[0] > 0){
        res = min(res, 1LL * (cnt[0]-1) * x + y);
    }
    cout << res;



}