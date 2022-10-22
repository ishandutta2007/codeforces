#include <iostream>

using namespace std;

int main() {
    int h1, h2, a, b, sum = 0;
    cin >> h1 >> h2 >> a >> b;
    //int l = 12 * (a - b);
  //  h1 -= 4 * a;
    if (a <= b && h1 + 8 * a < h2) {
        cout << -1 << endl;
        return 0;
    } else {
        h1 += 8 * a;
        while (h1 < h2) {
            h1 += 12 * (a - b);
            sum++;
        }
    }
    cout << sum << endl;
}