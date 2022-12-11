#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(2*n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < n; ++i) arr[i+n] = arr[i];
    vector<int> yeet(2*n + 1);
    for (int i = 0; i < 2*n; ++i) {
        if (arr[i] == 0) yeet[i+1] = 0;
        else yeet[i+1] = yeet[i] + 1;
    }
    printf("%d\n", *max_element(yeet.begin(), yeet.end()));
    return 0;
}