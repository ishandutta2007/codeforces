#include <cstdio>
using namespace std;
const int N = 3e5 + 1;

int n, q, p, a[N], b[N], fib[N] = {0, 1, 1}, l, r, ans;
char opt;

int main(){
    scanf("%d%d%d", &n, &q, &p);
    for (int i = 3; i <= n; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % p;
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        a[i] = (b[i] - a[i] + p) % p;
    }
    for (int i = n; i > 1; i--){
        a[i] = ((a[i] - a[i - 1] - a[i - 2]) % p + p) % p;
    }
    for (int i = 1; i <= n; i++)
        if(a[i] != 0)
            ans++;
    while(q--){
        scanf(" %c%d%d", &opt, &l, &r);
        if(opt == 'A'){
            if(a[l] == 0)
                ans++;
            a[l] = (a[l] - 1 + p) % p;
            if(a[l] == 0)
                ans--;
            if(r < n){
                if(a[r + 1] == 0)
                    ans++;
                a[r + 1] = (a[r + 1] + fib[r - l + 2]) % p;
                if(a[r + 1] == 0)
                    ans--;
            }
            if(r + 1 < n){
                if(a[r + 2] == 0)
                    ans++;
                a[r + 2] = (a[r + 2] + fib[r - l + 1]) % p;
                if(a[r + 2] == 0)
                    ans--;
            }
        }
        else{
            if(a[l] == 0)
                ans++;
            a[l] = (a[l] + 1) % p;
            if(a[l] == 0)
                ans--;
            if(r < n){
                if(a[r + 1] == 0)
                    ans++;
                a[r + 1] = (a[r + 1] - fib[r - l + 2] + p) % p;
                if(a[r + 1] == 0)
                    ans--;
            }
            if(r + 1 < n){
                if(a[r + 2] == 0)
                    ans++;
                a[r + 2] = (a[r + 2] - fib[r - l + 1] + p) % p;
                if(a[r + 2] == 0)
                    ans--;
            }
        }
        puts(ans == 0 ? "YES" : "NO");
    }
}