#include <cstdio>
#include <algorithm>
#include <vector>

int N, L, X, Y;
int a[100005];
std::vector<int> x;
std::vector<int> y;

bool check(std::vector<int> &v) {
    int i = 0, j = 0;
    while (i < N && j < (int)v.size()) {
        if (a[i] == v[j]) return true;
        else if (a[i] < v[j]) i++;
        else j++;
    }
    return false;
}

int main()
{
    scanf("%d%d%d%d", &N, &L, &X, &Y);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < N; i++) {
        x.push_back(a[i]+X);
        x.push_back(a[i]-X);
        y.push_back(a[i]+Y);
        y.push_back(a[i]-Y);
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    
    if (check(x) && check(y)) printf("0\n");
    else if (check(x)) printf("1\n%d\n", Y);
    else if (check(y)) printf("1\n%d\n", X);
    else {
        int i = 0, j = 0;
        while (i < (int)x.size() && j < (int)y.size()) {
            if (x[i] == y[j] && 0 < x[i] && x[i] < L) {
                printf("1\n%d\n", x[i]);
                return 0;
            }
            else if (x[i] < y[j]) i++;
            else j++;
        }
        printf("2\n%d %d\n", X, Y);
    }
}