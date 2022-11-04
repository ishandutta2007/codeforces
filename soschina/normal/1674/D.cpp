#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = n - 1; i > 0; i -= 2)
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        bool flag = true;
        for (int i = 1; i < n; i++)
            if(a[i] > a[i + 1])
                flag = false;
        puts(flag ? "YES" : "NO");
    }
	return 0;
}