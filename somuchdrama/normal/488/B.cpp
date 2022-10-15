#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define vc vector
//  -

//ifstream IN(".in");
//ofstream OUT(".out")
//

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

int main(){
    int n; cin >> n;
    vc<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    if(n == 4){
        if((A[3] - A[0]) * 4 == A[0] + A[1] + A[2] + A[3] and (A[3] - A[0]) * 2 == A[1] + A[2]){
            cout << "YES";
        }else{
            cout << "NO";
        }
        return 0;
    }
    if(n == 3){
        for(int i = 1; i <= A[0]; ++i){
            if((A[2] - i) * 4 == i + A[0] + A[1] + A[2] and (A[2] - i) * 2 == A[0]+ A[1]){
                cout << "YES\n" << i;
                return 0;
            }
        }
        for(int i = A[0]; i <= A[2]; ++i){
            if((A[2] - A[0]) * 4 == i + A[0] + A[1] + A[2] and (A[2] - A[0]) * 2 == i + A[1]){
                cout << "YES\n" << i;
                return 0;
            }
        }
        for(int i = A[2]; i <= 1000000; ++i){
            if((i - A[0]) * 4 == i + A[0] + A[1] + A[2] and (i - A[0]) * 2 == A[2] + A[1]){
                cout << "YES\n" << i;
                return 0;
            }
        }
    }
    if(n == 2){
        if(A[0] == A[1]){
                cout << "YES\n" << (3 * A[0]) << "\n" << (3 * A[0]);
            return 0;
        }else{
            if(4 * A[0] - A[1] > 0){
                cout << "YES\n" << (4 * A[0] - A[1]) << "\n" << (3 * A[0]);
            return 0;
            }
        }
    }
    if(n == 1){
        cout << "YES\n" << A[0] << "\n" << (3 * A[0]) << "\n" << (3 * A[0]);
        return 0;
    }
    if(n == 0){
        cout << "YES\n" << 1 << "\n" << 1 << "\n" << 3 << "\n" << 3;
        return 0;
    }
    cout << "NO";
//    IN.lse();
//    OUT.close();
    return 0;
}