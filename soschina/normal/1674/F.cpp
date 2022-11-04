#include <cstdio>
using namespace std;
const int N = 1001;

int n, m, q, x, y, sum, cnt;
bool ocupied[N * N];
char c;

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            int id = j * n + i;
            scanf(" %c", &c);
            if(c == '*'){
                sum++;
                ocupied[id] = 1;
            }
        }
    for (int i = 0; i < sum; i++)
        if(ocupied[i])
            cnt++;
    while(q--){
        scanf("%d%d", &x, &y);
        x--, y--;
        int id = y * n + x;
        if(id < sum){
            if(ocupied[id])
                cnt--;
            else
                cnt++;
        }
        ocupied[id] ^= 1;
        if(ocupied[id]){
            if(ocupied[sum])
                cnt++;
            sum++;
        }else{
            sum--;
            if(ocupied[sum])
                cnt--;
        }
        printf("%d\n", sum - cnt);
    }
    return 0;
}