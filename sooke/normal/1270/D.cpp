#include <bits/stdc++.h>

int resi, resx;

void query(std::vector<int> vec) {
    std::cout << "?";
    for (auto i : vec) { std::cout << " " << i; }
    std::cout << std::endl;
    std::cin >> resi >> resx;
}

int n, m, k, nowi, nowx, tmpi, tmpx, ai, ax;
std::vector<int> now, tmp, a;

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= k; i++) { now.push_back(i); }
    query(now); nowi = resi; nowx = resx;
    for (int i = 1; i <= k + 1; i++) {
        if (i != nowi) { tmp.push_back(i); }
    }
    query(tmp); tmpi = resi; tmpx = resx;
    if (tmpi == k + 1) {
        m = 1;
        for (int i = 1; i <= k; i++) {
            if (i != nowi) {
                a.clear();
                for (int j = 1; j <= k; j++) {
                    if (i != j) { a.push_back(j); }
                }
                a.push_back(k + 1);
                query(a);
                if (nowx < tmpx) {
                    if (resi == tmpi) { m++; }
                } else {
                    if (resi == nowi) { m++; }
                }
            }
        }
    } else {
        m = 1;
        for (int i = 0; i < k; i++) {
            if (tmp[i] == tmpi) { continue; }
            a = tmp;
            for (int j = 0; j < k; j++) {
                if (a[j] == tmp[i]) { a[j] = nowi; break; }
            }
            query(a);
            if (nowx < tmpx) {
                if (resi == tmpi) { m++; }
            } else {
                if (resi != tmpi) { m++; }
            }
        }
    }
    std::cout << "! " << m << std::endl;
    return 0;
}