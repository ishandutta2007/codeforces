#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long LL;

int n , a , b , c , d;
int s0 , t0 , a0 , b0;
int s1 , t1 , a1 , b1;
int f[N];
int main() {
    cin >> n;
    cin >> s0 >> t0 >> a0 >> b0;
    cin >> s1 >> t1 >> a1 >> b1;

    memset(f , -1 , sizeof(f));

    int x;
    x = s0 , a = b = -1;
    for (int i = 0 ; i < N + N && !~b ; ++ i) {
        if (x == t0) {
            if (!~a)
                a = i;
            else
                b = i;
        }
        x = ((LL) x * a0 + b0) % n;
    }
    x = s1 , c = d = -1;
    for (int i = 0 ; i < N + N && !~d ; ++ i) {
        if (x == t1) {
            if (!~c)
                c = i;
            else
                d = i;
        }
        x = ((LL) x * a1 + b1) % n;
    }
    if (!~a || !~c)
        puts("-1");
    else {
        if (!~b && !~d) {
            if (a == c) {
                cout << a << endl;
            } else {
                puts("-1");
            }
        } else if (!~b) {
            if (a == c || a == d) {
                cout << a << endl;
            } else {
                puts("-1");
            }  
        } else if (!~d) {
            if (c == a || c == b) {
                cout << c << endl;
            } else {
                puts("-1");
            }  
        } else {
            swap(a , b);
            a -= b;
            swap(c , d);
            c -= d;
            for (int i = 0 ; i < N ; ++ i) {
                LL t = (LL) i * a + b;
                if (t >= d && (t - d) % c == 0) {
                    cout << t << endl;
                    return 0;
                }                
            }
            puts("-1");
        }
    }
    
    
    
    
    return 0;
}