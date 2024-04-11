#include <iostream>
#include <stack>
using namespace std;

int a[100000 + 10], n, top = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        a[++top] = 1;
        while(a[top] == a[top-1]) {
            a[top - 1] ++;
            top --;
        }
    }

    for(int i = 1; i <= top; i ++) {
        printf("%d ", a[i]);
    }
}