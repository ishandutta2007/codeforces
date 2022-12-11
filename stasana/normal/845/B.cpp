#include <iostream>
#include <string>

using namespace std;

bool check(int n) {
    int f = n / 1000;
    int s = n % 1000;
    return f % 10 + f / 10 % 10 + f / 100 == s % 10 + s / 10 % 10 + s / 100;
}

int pow(int i) {
    return i == 0 ? 1 : 10 * pow(i - 1);
}

int get_index(int a, int index) {
    return (a / pow(5 - index)) % 10;
}

int get_res(int a, int b) {
    int res = 0;
    for (int i = 0; i < 6; ++i) {
        if (get_index(a, i) != get_index(b, i)) {
            ++res;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int res = 100;
    for (int i = 0; i < 1000000; ++i) {
        if (check(i)) {
            int new_res = get_res(n, i);
            if (res >= new_res) {
                res = new_res;
            }
        }
    }

    cout << res << endl;
    return 0;
}