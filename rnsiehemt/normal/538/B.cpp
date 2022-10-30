#include <bits/stdc++.h>

int N;
std::vector<int> v;

int main()
{
    scanf("%d", &N);
    while (N) {
        int cur = 0;
        for (int k = 1; k <= 1000*10000; k*=10) {
            if ((N%(k*10))/k) {
                cur += k;
                N -= k;
            }
        }
        v.push_back(cur);
    }
    printf("%d\n", (int)v.size());
    for (int i = 0; i < (int)v.size(); i++)
        printf("%d%c", v[i], " \n"[i == (int)v.size()-1]);
}