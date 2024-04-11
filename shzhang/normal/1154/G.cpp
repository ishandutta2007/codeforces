#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

ll best = 1000000000000000000LL; int choice1, choice2;
bool present[10000007];
int idx[10000007];

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if (present[val]) {
            if (val < best) {
                best = val; choice1 = idx[val]; choice2 = i;
            }
        }
        present[val] = true; idx[val] = i;
    }
    for (int common = 1; common <= 10000000; common++) {
        vector<int> vals;
        for (int i = common; i <= 10000000; i += common) {
            if (present[i]) {
                vals.push_back(i);
                if (vals.size() >= 2) break;
            }
        }
        if (vals.size() >= 2) {
            if (((ll)vals[0] * (ll)vals[1]) / (ll)common < best) {
                best = ((ll)vals[0] * (ll)vals[1]) / (ll)common;
                choice1 = idx[vals[0]]; choice2 = idx[vals[1]];
            }
        }
    }
    if (choice1 > choice2) {
        int t = choice1; choice1 = choice2; choice2 = t;
    }
    printf("%d %d", choice1, choice2);
    return 0;
}