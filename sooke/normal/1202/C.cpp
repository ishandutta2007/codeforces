#include <bits/stdc++.h>

const int N = 1e6 + 5;

int T, n;
long long prex[N], prey[N], preminx[N], preminy[N], premaxx[N], premaxy[N];
long long sufx[N], sufy[N], sufminx[N], sufminy[N], sufmaxx[N], sufmaxy[N];

std::string str;

inline long long get(long long pminx, long long pminy, long long pmaxx, long long pmaxy, long long sminx, long long sminy, long long smaxx, long long smaxy) {
    long long minx = std::min(pminx, sminx);
    long long miny = std::min(pminy, sminy);
    long long maxx = std::max(pmaxx, smaxx);
    long long maxy = std::max(pmaxy, smaxy);
    return (maxx - minx + 1) * (maxy - miny + 1);
}

long long solve() {
    n = str.size();
    prex[0] = prey[0] = preminx[0] = preminy[0] = premaxx[0] = premaxy[0] = 0;
    sufx[n] = sufy[n] = sufminx[n] = sufminy[n] = sufmaxx[n] = sufmaxy[n] = 0;
    for (int i = 1; i < n; i++) {
        prex[i] = prex[i - 1]; prey[i] = prey[i - 1];
        preminx[i] = preminx[i - 1]; preminy[i] = preminy[i - 1];
        premaxx[i] = premaxx[i - 1]; premaxy[i] = premaxy[i - 1];
        switch (str[i]) {
            case 'W': {
                prex[i]--; break;
            }
            case 'S': {
                prex[i]++; break;
            }
            case 'A': {
                prey[i]--; break;
            }
            case 'D': {
                prey[i]++; break;
            }
        }
        preminx[i] = std::min(preminx[i], prex[i]);
        preminy[i] = std::min(preminy[i], prey[i]);
        premaxx[i] = std::max(premaxx[i], prex[i]);
        premaxy[i] = std::max(premaxy[i], prey[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        sufx[i] = sufx[i + 1]; sufy[i] = sufy[i + 1];
        sufminx[i] = sufminx[i + 1]; sufminy[i] = sufminy[i + 1];
        sufmaxx[i] = sufmaxx[i + 1]; sufmaxy[i] = sufmaxy[i + 1];
        switch (str[i]) {
            case 'W': {
                sufx[i]++; break;
            }
            case 'S': {
                sufx[i]--; break;
            }
            case 'A': {
                sufy[i]++; break;
            }
            case 'D': {
                sufy[i]--; break;
            }
        }
        sufminx[i] = std::min(sufminx[i], sufx[i]);
        sufminy[i] = std::min(sufminy[i], sufy[i]);
        sufmaxx[i] = std::max(sufmaxx[i], sufx[i]);
        sufmaxy[i] = std::max(sufmaxy[i], sufy[i]);
    }
    for (int i = 0; i <= n; i++) {
        sufminx[i] -= sufx[i];
        sufminy[i] -= sufy[i];
        sufmaxx[i] -= sufx[i];
        sufmaxy[i] -= sufy[i];
    }
    long long ans = (sufmaxx[1] - sufminx[1] + 1) * (sufmaxy[1] - sufminy[1] + 1);
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, get(preminx[i], preminy[i], premaxx[i], premaxy[i], prex[i] + sufminx[i + 1] - 1, prey[i] + sufminy[i + 1], prex[i] + sufmaxx[i + 1] - 1, prey[i] + sufmaxy[i + 1]));
        ans = std::min(ans, get(preminx[i], preminy[i], premaxx[i], premaxy[i], prex[i] + sufminx[i + 1] + 1, prey[i] + sufminy[i + 1], prex[i] + sufmaxx[i + 1] + 1, prey[i] + sufmaxy[i + 1]));
        ans = std::min(ans, get(preminx[i], preminy[i], premaxx[i], premaxy[i], prex[i] + sufminx[i + 1], prey[i] + sufminy[i + 1] - 1, prex[i] + sufmaxx[i + 1], prey[i] + sufmaxy[i + 1] - 1));
        ans = std::min(ans, get(preminx[i], preminy[i], premaxx[i], premaxy[i], prex[i] + sufminx[i + 1], prey[i] + sufminy[i + 1] + 1, prex[i] + sufmaxx[i + 1], prey[i] + sufmaxy[i + 1] + 1));
    }
    return ans;
}

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> str; str = " " + str;
        std::cout << solve() << std::endl;
    }
    return 0;
}