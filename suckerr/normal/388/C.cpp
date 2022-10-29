#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;
const int INF = 1000000000;

int n, ans1, ans2;
vector<int> vec;

int main() {
    
    int tot = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int s;
        scanf("%d", &s);
        for(int j = 0; j < s / 2; j++) {
            int x;
            scanf("%d", &x);
            ans1 += x;
        }
        
        if (s % 2 == 1) {
            int x;
            scanf("%d", &x);
            vec.push_back(x);
        }
        
        for(int j = (s + 1) / 2; j < s; j++) {
            int x;
            scanf("%d", &x);
            ans2 += x;
        }
    }   
    
    sort(vec.begin(), vec.end());
    int sign = 1;
    for(int i = (int)vec.size() - 1; i >= 0; i--) {
        if (sign == 1)
            ans1 += vec[i];
        else
            ans2 += vec[i];
        
        sign = -sign;
    }
    
    printf("%d %d\n", ans1, ans2);
    return 0;
}