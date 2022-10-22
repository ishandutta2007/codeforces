#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int main() {
    int a , b;
    cin >> a >> b;
    vector<int> A, B;

    int x = 0;
    while (1LL * x * (x + 1) / 2 <= a + b) {
        ++ x;
    } -- x;

    for (int i = x ; i > 0 ; -- i) {
        if (a >= i) {
            a -= i;
            A.emplace_back(i);
        } else {
            assert(b >= i);
            b -= i;
            B.emplace_back(i);
        }
    }


    printf("%d\n" , A.size());
    for (int i = 0 ; i < A.size() ; ++ i) {
        printf("%d%c" , A[i] , " \n"[i + 1 == A.size()]);
    }
    printf("%d\n" , B.size());
    for (int i = 0 ; i < B.size() ; ++ i) {
        printf("%d%c" , B[i] , " \n"[i + 1 == B.size()]);
    }
}