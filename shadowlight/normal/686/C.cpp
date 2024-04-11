#include <iostream>
#include <vector>

using namespace std;

int n, m;
int num1 = 0, num2 = 0;
vector <int> used(7, 0);
vector <int> pows(10, 0);
int cnt = 0;
void generate(int sum_h, int sum_m, int hours, int mins) {
    if (sum_h >= n || sum_m >= m) return;
    if (hours != num1) {
        for (int i = 0; i < 7; i++) {
            if (used[i]) continue;
            used[i] = 1;
            generate(sum_h + pows[hours] * i, sum_m, hours + 1, mins);
            used[i] = 0;
        }
    } else if (mins != num2) {
        for (int i = 0; i < 7; i++) {
            if (used[i]) continue;
            used[i] = 1;
            generate(sum_h, sum_m + pows[mins] * i, hours, mins + 1);
            used[i] = 0;
        }
    } else {
        cnt++;
        //cout << sum_h << " " << sum_m << endl;
    }
}

int log7(int n) {
    int sum = 0, k = 1;
    while (n > 0) {
        n -= 6 * k;
        k *= 7;
        sum++;
    }
    return sum;
}

int main() {
    cin >> n >> m;
    int k = 1;
    int n1 = n;
    num1 = log7(n - 1);
    num2 = log7(m - 1);
    if (n == 1) num1 = 1;
    if (m == 1) num2 = 1;
    //cout << num1 << " " << num2 << endl;
    if (num1 + num2 > 7) {
        cout << 0;
        return 0;
    }
    pows[0] = 1;
    for (int i = 1; i < 10; i++) {
        pows[i] = pows[i - 1] * 7;
    }
    generate(0, 0, 0, 0);
    cout << cnt;
}