#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    if(n <= 5){
        cout << -1 << endl;
        for(int i = 1; i < n; i++){
            printf("%d %d\n", i, i+1);
        }
        return 0;
    }
    printf("1 2\n2 3\n2 4\n3 5\n3 6\n");
    for(int i = 7; i <= n; i++){
        if(i == 7) printf("7 2\n");
        else printf("%d %d\n", i, i-1);
    }
    for(int i = 1; i < n; i++){
        printf("%d %d\n", i, i+1);
    }
}