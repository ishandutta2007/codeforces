#include <bits/stdc++.h>

using namespace std;

int a, b, k;
int val[2][2];

int main() {
    scanf("%d%d%d",&a,&b,&k);
    int n = a + b;
    vector<int>ans1,ans2;
    if (a == 0 || b == 1 || k == 0) {
        if (k == 0) {
            for (int i=1;i<=b;i++) {
                ans1.push_back(1);
                ans2.push_back(1);
            }
            for (int i=1;i<=a;i++) {
                ans1.push_back(0);
                ans2.push_back(0);
            }
        } else {
            puts("No");
            return 0;
        }
    } else {
        if (k > n - 2) {
            puts("No");
            return 0;
        }
        b -= 2;
        a -= 1;
        ans1.push_back(0);
        ans2.push_back(1);
        for (int i=0;i<k-1;i++) {
            if (b>0) {
                ans1.push_back(1);
                ans2.push_back(1);
                b--;
            } else {
                ans1.push_back(0);
                ans2.push_back(0);
                a--;
            }
        }
        ans1.push_back(1);
        ans2.push_back(0);
        while(a > 0 || b > 0) {
            if (b>0) {
                ans1.push_back(1);
                ans2.push_back(1);
                b--;
            } else {
                ans1.push_back(0);
                ans2.push_back(0);
                a--;
            }
        }
        ans1.push_back(1);
        ans2.push_back(1);
        reverse(ans1.begin(), ans1.end());
        reverse(ans2.begin(), ans2.end());
    }
    puts("Yes");
    for (auto &t:ans1) printf("%d",t);puts("");
    for (auto &t:ans2) printf("%d",t);puts("");
}