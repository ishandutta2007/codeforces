#include <iostream>
#include <vector>
using namespace std;
const int N = 100000+10;
int n, a[N], res[N], ans[N];

void solve1() {
    int R = n;
    for (int i = n; i >= 1; i --) {
        if ((a[R] & a[i]) == 0) {
            for (int pos = i; pos <= R; pos ++) 
                res[pos] = a[R+i-pos];
            R = i - 1;
        }
    }
    if (R == 0) {
        printf("YES\n");
        for (int i = 1; i <= n; i ++) printf("%d ", res[i]);
        printf("\n");
    } else {
        printf("NO\n");
    }
}

void solve2() {
    if (n <= 5) {
        printf("NO\n"); return;
    }
    int t = n;
    while (t % 2 == 0) t /= 2;
    if (t == 1) {
        printf("NO\n");
        return;
    }

    for (int i = 1; i <= n; i ++)
        ans[i] = i;

    swap(ans[1], ans[5]);
    for (int low = 1; (1<<low) <= n; low ++) {
        vector<int> tmp;
        for (int i = 0; (i < (1<<low)) && ((i + (1<<low)) <= n); i ++) {
            if (i+(1<<low) != 5) {
                //printf("%d\n", i+(1<<low));
                tmp.push_back(i+(1<<low));
            }
        }
        //printf("-----\n");
        for (int i = 0; i < (int)tmp.size()-1; i ++)
            ans[tmp[i]] = tmp[i+1];
        ans[tmp[tmp.size()-1]] = tmp[0];
    }
    
    printf("YES\n");
    for (int i = 1; i <= n; i ++) {
        printf("%d ", ans[i]);   
    }    
    printf("\n");
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        a[i] = i;
    solve1();
    solve2();
}



/*




*/