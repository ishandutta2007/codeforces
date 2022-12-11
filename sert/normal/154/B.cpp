#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

#define fr(i, n) for(int i = 0; i < n; i++)
const int N = 1e6 + 7;
const ll md = 1e9 + 9;

int u[N];
bool on[N];
int n, m;
char ch;
int len;
int p[N];

void fuck_it(int we){
    int x = we;
    len = 0;
    int q = sqrt(x);

    for(int i = 2; i <= q; i++)
        if (x % i == 0){
            while(x % i == 0)
                x /= i;
            p[len++] = i;
        }
    if (x != 1)
        p[len++] = x;
    return;
}

int main(){

    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    int x;
    bool fail;

    fr(i, m){
        cin >> ch >> x;
        if (ch == '+' && on[x]){
            cout << "Already on\n";
            continue;
        }
        if (ch == '-' && !on[x]){
            cout << "Already off\n";
            continue;
        }
        fuck_it(x);
        if (ch == '-'){
            on[x] = false;
            fr(i, len)
                u[p[i]] = 0;
            cout << "Success\n";
        }
        if (ch == '+'){
            fail = false;
            fr(i, len)
                if (u[p[i]] != 0){
                    cout << "Conflict with " << u[p[i]] << "\n";
                    fail = true;
                    break;
                }
            if (fail) continue;
            fr(i, len)
                u[p[i]] = x;
            cout << "Success\n";
            on[x] = true;
        }
    }


    return 0;
}