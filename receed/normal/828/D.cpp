#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, k, num = 1;
    cin >> n >> k;
    if(k == 2){
        printf("%d\n", n - 1);
        for(int i = 1; i < n; i++)
            printf("%d %d\n", i, i + 1);
        return 0;
    }
    n--;
    if(n % k == 1)
        printf("%d\n", n / k * 2 + 1);
    else if(n % k == 0)
        printf("%d\n", n / k * 2);
    else
        printf("%d\n", n / k * 2 + 2);
    for(int i = 0; i < n % k; i++){
        printf("%d %d\n", 1, ++num);
        for(int j = 0; j < n / k; j++){
            printf("%d ", num);
            printf("%d\n", ++num);
        }
    }
    for(int i = 0; i < k - n % k; i++){
        printf("%d %d\n", 1, ++num);
        for(int j = 0; j < n / k - 1; j++){
            printf("%d ", num);
            printf("%d\n", ++num);
        }
    }
}