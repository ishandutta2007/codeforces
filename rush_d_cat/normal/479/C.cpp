#include <iostream>
#include <algorithm>
using namespace std;
const int NICO = 5002;
int n;
struct Test {
    int a, b;
} test[NICO];

bool cmp(Test x, Test y) {
    if(x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d %d", &test[i].a, &test[i].b);
    }
    sort(test+1, test+1+n, cmp);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(test[i].b >= ans) {
            ans = test[i].b;
        } else {
            ans = test[i].a;
        }
    } 
    cout << ans << endl;
}