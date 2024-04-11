#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n%2==0) {
        printf("%d %d\n", 4, n-4);
    } else{
        printf("%d %d\n", 9, n-9);
    }
}