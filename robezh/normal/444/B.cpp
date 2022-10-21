#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500, mod = (int)1e9 + 7;
#define swap(a, b) auto tmp = a; a = b; b = tmp;

ll x;
int get_next(){
    x = (x * 37 + 10007) % mod;
    return (int)x;
}

int n,d;
int a[N], b[N];
int s = 30;
int loc[N];
vector<int> one;


int main(){
    scanf("%d%d%I64d", &n, &d, &x);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    for(int i = 0; i < n; i++){
        int &x = a[i], &y = a[get_next() % (i + 1)];
        swap(x, y);
    }
    for(int i = 0; i < n; i++) b[i] = (i < d);
    for(int i = 0; i < n; i++){
        int &x = b[i], &y = b[get_next() % (i + 1)];
        swap(x, y);
    }
    for(int i = 0; i < n; i++){
        loc[a[i]] = i;
        if(b[i]) one.push_back(i);
    }

    for(int i = 0; i < n; i++){
        int rb = max(n - s + 1, 1);
        int res = 0;
        for(int j = n; j >= rb; j--){
            if(loc[j] >= 0 && loc[j] <= i && b[i - loc[j]]){
                res = j;
                break;
            }
        }
        if(res == 0){
            for(int j : one){
                if(j > i) break;
                res = max(res, a[i-j]);
            }
        }
        printf("%d\n", res);
    }


}