#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL k, p;

int pow(int a, int b) {
    int ans = 1;
    for (int i=1;i<=b;i++) {
        ans *= a;
    }
    return ans;
}
int len(int x) {
    int res = 0;
    while (x) {
        res ++; x /= 10;
    }
    return res;
}

int rev(int x) {
    vector<int> v; v.clear();
    while (x) {
        v.push_back(x%10); x/=10;
    }
    int ans = 0;
    for (int i=0;i<v.size();i++) {
        ans = ans * 10 + v[i];
    }
    return ans;
}


int main() {
    //cout << rev(123) << endl;
    cin >> k >> p;
    LL ans = 0;
    for (int i=1;i<=k;i++) {
        ans = ans + rev(i) + (LL)i * pow(10, len(i));
        ans %= p;
    }
    cout << ans << endl;
}