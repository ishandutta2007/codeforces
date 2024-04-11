#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

void work() {
    string S;
    cin >> S;
    int n = S.size();
    for (int i = 0 ; i <= n ; ++ i) {
        for (char j = 'a' ; j <= 'z' ; ++ j) {
            string A = S.substr(0 , i) + j + S.substr(i , n);
            string B = A;
            reverse(A.begin() , A.end());
            if (A == B) {
                cout << B << endl;
                return;
            }
        }
    }
    puts("NA");
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}