#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int L = 5005;

int n,m;
int gcd[L][L];
vector<P> res;

bool is_prime(int x){
    for(int i = 2; i < x; i++) if(x % i == 0) return false;
    return true;
}

int get_gcd(int x, int y){
    if(gcd[x][y] != -1) return gcd[x][y];
    return gcd[x][y] = (x == 0 ? y : get_gcd(y % x, x));
}

int main() {
    for(int i = 0; i < L; i++) for(int j = 0; j < L; j++) gcd[i][j] = -1;
    cin >> n >> m;
    if(n - 1 > m) return !printf("Impossible");
    if(n <= 5000){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(res.size() < m && get_gcd(i, j) == 1) res.emplace_back(i, j);
            }
        }
        if(res.size() < m) printf("Impossible");
        else{
            printf("Possible\n");
            for(P p : res) printf("%d %d\n", p.first, p.second);
        }
    }
    else{
        for(int i = 1; i < 400; i++){
            if(res.size() < m && is_prime(i)){
                for(int j = i + 1; j <= n; j++){
                    if(res.size() < m && (j % i != 0 || i == 1)) res.emplace_back(i, j);
                }
            }
        }
        printf("Possible\n");
        for(P p : res) printf("%d %d\n", p.first, p.second);
    }

}