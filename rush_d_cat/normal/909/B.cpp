 #include <iostream>
using namespace std;
int n;
int f[102];
int main() {
    f[0] = 0;
    int c = 0;
    for (int i = 0; i < 100; i ++) {
        if (i % 2 == 0) c ++;
        f[i+1] = f[i] + c;
    }
    cin >> n;
    printf("%d\n", f[n]);
}