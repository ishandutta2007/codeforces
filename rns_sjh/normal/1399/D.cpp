#include<bits/stdc++.h>
using namespace std;

#define N 200020

char s[N];
vector<int> x, y;
int a[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int m = 0;
        x.clear(), y.clear();
        for(int i = 1; i <= n; i ++) {
            if(s[i] == '0') {
                if(x.size()) a[i] = a[x[x.size() - 1]], x.pop_back(), y.push_back(i);
                else y.push_back(i), a[i] = ++ m;
            }
            if(s[i] == '1') {
                if(y.size()) a[i] = a[y[y.size() - 1]], y.pop_back(), x.push_back(i);
                else x.push_back(i), a[i] = ++ m;
            }
        }
        printf("%d\n", m);
        for(int i = 1; i < n; i ++) printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
}