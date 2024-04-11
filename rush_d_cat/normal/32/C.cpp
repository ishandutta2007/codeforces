#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL n, m, s;
LL md(LL x, LL y) {
    if(x%y == 0) return y;
    return x%y;
}
int main() {

    cin >> n >> m >> s;
    LL row = 0, col = 0;
    LL x = m%s==0?s:m%s;
    LL y = n%s==0?s:n%s;
    for(int i=1;i<=m;i++) if(md(i, s) <= x || md(m-i+1, s) <= x) row++;
    for(int i=1;i<=n;i++) if(md(i, s) <= y || md(n-i+1, s) <= y) col++;
    cout << (row * col) << endl;
}