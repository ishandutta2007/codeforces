#include <cstdio>
#include <vector>
using namespace std;
const int N = 4e4 + 1, M = 501, p = 1e9 + 7;

int t, n, a[10], f[N] = {1}, len;
vector<int> palin;

bool ispalin(int x){
    len = 0;
    while(x){
        a[len++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < len; i++)
        if(a[i] != a[len - i - 1])
            return false;
    return true;
}

int main(){
    for (int i = 1; i < N; i++){
        if(ispalin(i))
            palin.push_back(i);
        f[i] = 1;
    }
    for (int i = 1; i < palin.size(); i++)
        for (int j = 1; j < N; j++)
            if(j >= palin[i])
                f[j] = (f[j] + f[j - palin[i]]) % p;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}