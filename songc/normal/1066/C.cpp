#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
typedef long long LL;

int N;
int L, R;
map< int, pii > M;

int main(){
    char ch;
    int x;
    scanf("%d", &N);
    scanf(" %c %d", &ch, &x);
    M[x] = pii(0, 0);
    for (int i=2; i<=N; i++){
        scanf(" %c %d", &ch, &x);
        if (ch == 'L'){
            L++;
            M[x] = pii(-L, L);
        }
        if (ch == 'R'){
            R++;
            M[x] = pii(R, -R);
        }
        if (ch == '?') printf("%d\n", min(M[x].first+L, M[x].second+R));
    }
    return 0;
}