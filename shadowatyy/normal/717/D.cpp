#include<bits/stdc++.h>
using namespace std;

const int N = 303;

int k;

long double tbl[N], wyn[N], tmp[N];

void tmpclear() {
    for (int i = 0; i <= k; i++) {
        tmp[i] = 0;
    }
}

void tmpcopy() {
    for (int i = 0; i <= k; i++) {
        wyn[i] = tmp[i];
    }
}

void domnoz() {
    tmpclear();
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            tmp[i ^ j] += tbl[i] * wyn[j];
        }
    }
    tmpcopy();
}

void kwadrat() {
    tmpclear();
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            tmp[i ^ j] += wyn[i] * wyn[j];
        }
    }
    tmpcopy();
}

void odp(int n) {
    if (n == 0)
        return;
    odp(n / 2);
    kwadrat();
    if (n % 2 == 1) {
        domnoz();
    }
}

int main() {
    int n;
    cin >> n >> k;
    for (int i = 0; i <= k; i++) {
        cin >> tbl[i];
    }
    int newk = 1;
    while(newk <= k) newk *= 2;
    k = newk;
    wyn[0] = 1;
    odp(n);
    cout << setprecision(12) << fixed << (long double) 1.0 - wyn[0];
    return 0;
}