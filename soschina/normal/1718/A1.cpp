#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];
map<int, int> mp;

int main(){
    scanf("%d", &t);
    while(t--){
        mp.clear();
        scanf("%d", &n);
        int maxans = 0;
        mp[0] = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i] ^= a[i - 1];
            if(mp.find(a[i]) == mp.end())
                mp[a[i]] = maxans;
            else
                mp[a[i]] = maxans = max(mp[a[i]] + 1, maxans);
        }
        printf("%d\n", n - maxans);
    }
    return 0;
}