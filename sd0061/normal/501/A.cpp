#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;

void work() {
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    int x = max(3 * a / 10 , a - a / 250 * c);
    int y = max(3 * b / 10 , b - b / 250 * d);
    if (x < y)
        puts("Vasya");
    if (x > y)
        puts("Misha");
    if (x == y)
        puts("Tie");
}

int main() {
    work();
    return 0;
}