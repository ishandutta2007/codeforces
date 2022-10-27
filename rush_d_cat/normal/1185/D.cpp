#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200000 + 10;
int n, a[N], b[N];
map<int,int> mp;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]); b[i] = a[i];
    }
    sort(b+1,b+1+n);
    if(n<=3) {
        return !printf("1\n");
    }
    for(int i=2;i<=n;i++) {
        mp[b[i] - b[i-1]] ++;
    }

    int del = -1e9-7;
    for(int i=2;i<n;i++) {
        mp[b[i+1]-b[i-1]]++;
        mp[b[i+1]-b[i]]--, mp[b[i]-b[i-1]]--;
        if(mp[b[i+1]-b[i-1]] == n-2) {
            del = b[i]; break;
        } 
        mp[b[i+1]-b[i-1]]--;
        mp[b[i+1]-b[i]]++, mp[b[i]-b[i-1]]++;
    }

    if(del == -1e9-7) {
        mp[b[2] - b[1]] --;
        if (mp[b[3] - b[2]] == n-2) {
            del = b[1];
        }
        mp[b[2] - b[1]] ++;
    }

    if(del == -1e9-7) {
        mp[b[n] - b[n-1]] --;
        if (mp[b[2] - b[1]] == n-2) {
            del = b[n];
        }
        mp[b[n] - b[n-1]] ++;
    }

    if (del == -1e9-7) return !printf("-1\n");
    for (int i = 1; i <= n;i ++) {
        if (a[i] == del) return !printf("%d\n", i);
    }
}