#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000000 + 10;
vector<int> now,ans;
int n,val=1;

bool solve() {
    if(now.size()==1) {
        ans.push_back(val);return 0;
    }
    if(now.size()==2) {
        ans.push_back(val); ans.push_back(2*val);return 0;
    }
    if(now.size()==3) {
        ans.push_back(val); ans.push_back(val); ans.push_back(3*val); return 0;
    }
    for(int i=0;i<now.size();i+=2) {
        ans.push_back(val);
    }
    vector<int> tmp;
    for(int i=1;i<now.size();i+=2) {
        tmp.push_back(now[i]/(2*val));
    }
    now = tmp; val *= 2;
    return 1;
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) now.push_back(i);
    while(solve());
    for(auto x: ans) printf("%d ", x);
}