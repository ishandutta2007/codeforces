#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool nomove = false;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] % 10 == 5)
                a[i] += 5;
            if(a[i] % 10 == 0)
                nomove = true;
            else{
                while(a[i] % 10 != 2)
                    a[i] += a[i] % 10;
            }
        }
        bool flag = true;
        if(nomove){
            for (int i = 2; i <= n; i++)
                if(a[i] != a[i - 1])
                    flag = false;
        }
        else{
            for (int i = 2; i <= n; i++)
                if((a[i] - a[i - 1]) % 20 != 0)
                    flag = false;
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}