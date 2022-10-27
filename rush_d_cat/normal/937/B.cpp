#include <iostream>
using namespace std;

int p, y;

bool isprime(int x) {
    for (int i = 2; i <= p && i * i <= x; i ++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    cin >> p >> y;
    for (int i = y; i > p && y - i < 2000; i --)
        if (isprime(i))
            return !printf("%d\n", i);
    printf("-1\n");
}