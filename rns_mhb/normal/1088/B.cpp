#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    set <int> s;
    while(n --) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    int m = 0;
    while(k --) {
        if(s.empty()) puts("0");
        else {
            printf("%d\n", *s.begin() - m);
            m = *s.begin();
            s.erase(s.begin());
        }
    }
}