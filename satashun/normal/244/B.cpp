#include <cstdio>
#include <set>
using namespace std;

set<int> nums;
int n;

void dfs(int x, int y, long long acc){
    if(acc > n) return;
    if(acc != 0) nums.insert(acc);
    if(!(acc == 0 && x == 0)) dfs(x, y, acc * 10 + x);
    if(!(acc == 0 && y == 0)) dfs(x, y, acc * 10 + y);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 10; i++) {
        for(int j = i; j < 10; j++){
            dfs(i, j, 0);
        }
    }
    printf("%d\n", nums.size());
    return 0;
}