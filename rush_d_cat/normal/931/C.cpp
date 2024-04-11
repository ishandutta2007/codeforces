#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> mp;
const int N = 100000+10;
int n, a[N];
int c[3], d[3];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), mp[a[i]] ++;
    
    int x = 0;
    for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it ++) {
        d[x] = it->first;
        c[x] = it->second;
        x ++;
    }
    
    if (mp.size() <= 2) {
        if (mp.size() == 2 && d[1]-d[0]==2) {
            c[2]=c[1], d[2]=d[1];
            c[1]=0, d[1]=d[2]-1;
        }  else {
        printf("%d\n", n);
        for (int i = 1; i <= n; i ++)
            printf("%d ", a[i]);
        return 0;
    }
    }

    int ans1 = c[1] - c[1] % 2;
    int ans2 = 2 * min(c[0], c[2]);

    if (ans1 < ans2) {
        printf("%d\n", n - ans2);
        if (c[0] < c[2]) {
            c[2] -= c[0], c[0] = 0;
        } else {
            c[0] -= c[2], c[2] = 0; 
        }
        c[1] = n - c[0] - c[2];
    } else {
        printf("%d\n", n - ans1);
        c[0] += ans1/2;
        c[2] += ans1/2;
        c[1] = n - c[0] - c[2];
    }
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < c[i]; j ++)
            printf("%d ", d[i]);
}