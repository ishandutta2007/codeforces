#include <iostream>
using namespace std;
int T, n;
int ok[2002];
void init() {
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++) {
            ok[3*i+7*j] = 1;
        }
}
int main() {
    init();
    cin >> T;
    while (T --) {
        cin >> n;
        printf("%s\n", ok[n]?"YES":"NO");
    }
}