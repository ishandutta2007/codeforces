#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
int a[502 * 502];
map<int, int> mp;
vector<int> all, tmp;

int gcd(int x, int y) {
    return y == 0 ? x: gcd(y, x%y);
}
int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n*n; i++) {
        scanf("%d", &a[i]); mp[a[i]] ++;
    }

    int cnt = 0;
    while(cnt != n) {

        int mx = 0;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it ++) {
            if(it -> second > 0) mx = it -> first;
        }

        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it ++) 
        {
            if((it -> second) % 2 || it -> first == mx) {
                printf("%d ", it->first);  cnt ++;
                tmp.push_back(it->first);
            }
        }

        for(int i = 0; i < tmp.size(); i ++) {
            for(int j = 0; j < tmp.size(); j ++) {
                mp[gcd(tmp[i], tmp[j])] --;
            }
        }

        for(int i = 0; i < all.size(); i ++) {
            for(int j = 0; j < tmp.size(); j ++) {
                mp[gcd(all[i], tmp[j])] -= 2;
            }
        }

        for(int i = 0; i < tmp.size(); i ++) {
            all.push_back(tmp[i]);
        }

        tmp.clear();
    }

}