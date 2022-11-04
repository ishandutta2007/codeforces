#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        bool one = false;
        bool zero = false;
        bool diff = false;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] == 1) one = true;
            if(a[i] == 0) zero = true;
        }
        sort(a + 1, a + 1 + n);
        for(int i = 1; i < n; i++){
            if(a[i + 1] - a[i] == 1) diff = true;
        }
        puts(one && diff ? "NO" : "YES");
    }
    return 0;
}