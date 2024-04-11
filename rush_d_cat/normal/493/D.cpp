#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    if(n % 2 == 0) {
        printf("white\n");
        printf("1 2\n");
    } else {
        printf("black\n");
    }
}