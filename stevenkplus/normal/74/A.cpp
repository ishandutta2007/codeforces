#include <cstdio>
#include <iostream>

using namespace std;
const int MAXN = 100100;

string best;
int highest = -100000000;
char buf[10000];

void process() {
    int plus,minus, a, b, c, d, e;
    scanf("%s %d %d %d %d %d %d %d", buf, &plus, &minus, &a, &b, &c, &d, &e);
    int sum = plus * 100 - minus * 50 + a + b + c + d + e;
    if (sum > highest) {
        highest = sum;
        best = string(buf);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        process();
    }
    printf("%s\n", best.c_str());
    return 0;
}