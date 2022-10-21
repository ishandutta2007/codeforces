#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10005;


int T;
int n, k;
//int sg[N];

//int get_sg(set<int> S) {
//    int cur = 0;
//    for(int x : S) {
//        if(x == cur) cur++;
//        else return cur;
//    }
//    return cur;
//}
int get_sg(int n, int k) {
    if(k % 3 != 0) return n % 3;
    int p = k + 1;
    int rem = n % p;
    if(rem <= k - 1) return rem % 3;
    else return 3;

}

//void print_sg() {
//    sg[0] = 0;
//    cout << 0 << " ";
//    for(int i = 1; i <= n; i++) {
//        set<int> S;
//        if(i >= 1) S.insert(sg[i-1]);
//        if(i >= 2) S.insert(sg[i-2]);
//        if(i >= k) S.insert(sg[i-k]);
//        sg[i] = get_sg(S);
////        if(sg[i] != get_sg(i, k)) {
////            cout << endl;
////            cout << i << " " << k << " ???" << endl;
////        }
//        cout << sg[i] << " ";
//
//    }
//    cout << endl;
//}
//


int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
//        print_sg();
        cout << (get_sg(n, k) == 0 ? "Bob" : "Alice") << endl;
    }
}