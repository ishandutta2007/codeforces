#include <iostream>
#include <map>
using namespace std;
int n;
int l[302], c[302];
map<int, int> mp;

int gcd(int x, int y) {
    return (y==0)? x : gcd(y, x%y);
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> l[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=n;i++) {
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
            int x = it -> first;
            int y = it -> second;
            int tmp = gcd(x, l[i]);
            int cost = y + c[i];
            if(mp.find(tmp) == mp.end()) mp[tmp] = cost;
            else if(mp[tmp] > cost) mp[tmp] = cost; 
        }

        if(mp.find(l[i]) == mp.end()) {
            mp[l[i]] = c[i];
        } else {
            mp[l[i]] = min(mp[l[i]], c[i]);
        }
    }
    if(mp[1] == 0) mp[1] = -1;
    cout << mp[1] << endl;
}