#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
ll a[100500], b[100500];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%I64d", &b[i]);

    ll sum1 = 0, sum2 = 0;
    int pos2 = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i];
        if(sum1 == sum2){
            cnt ++;
            sum1 = sum2 = 0;
        }
        else if(sum1 > sum2){
            while(sum1 > sum2){
                sum2 += b[pos2++];
            }
            if(sum1 == sum2){
                cnt ++;
                sum1 = sum2 = 0;
            }
        }
    }
    cout << cnt << endl;
}