#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 363304+10;
const LL MOD = 1e9 + 7;
vector<int> v;
set<int> st1, st2;
int n;
LL ans = 1;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        char op[10];int p;
        scanf("%s%d", op, &p);
        if (i==n && op[1]=='D') {
            v.push_back(p);
            int cnt = 0;
            for(auto x: v) {
                if ( (st1.size()==0||x>*st1.rbegin()) && (st2.size()==0||x<*st2.begin()) ) cnt ++;
            }
            ans = ans * (cnt + 1) % MOD;
            continue;
        }
        if (op[1] == 'C') {
            if ( (st1.size()==0||p>=*st1.rbegin()) && (st2.size()==0||p<=*st2.begin()) ){}
            else {
                ans = 0; continue;
            }

            for(auto x: v) {
                if(x<p) st1.insert(x);
                if(x>p) st2.insert(x);
            }
            v.clear();

            if (st1.count(p)) {
                if (p != *st1.rbegin()) ans = 0;
                st1.erase(p);
                continue;
            }
            if (st2.count(p)) {
                if (p != *st2.begin())  ans = 0;
                st2.erase(p); 
                continue;
            }
            if( (st1.size()==0||*st1.rbegin() < p) && (st2.size() == 0 || p < *st2.begin())) {
                ans = ans * 2LL % MOD;
            } else {
                ans = 0;
            }
        } else {
            v.push_back(p);
        }
    }
    cout << ans << endl;
}