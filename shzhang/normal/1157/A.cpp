#include <cstdio>
#include <vector>

using namespace std;

int f(int x)
{
    x++;
    while (x % 10 == 0) x /= 10;
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums;
    nums.push_back(n);
    while (true) {
        n = f(n);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == n) goto loop_end;
        }
        nums.push_back(n);
    }
    loop_end:
    printf("%d", nums.size());
    return 0;
}