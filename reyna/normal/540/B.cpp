//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,p,x,y;
    cin >> n >> k >> p >> x >> y;
    int sum = 0;
    int best = 0;
    for(int i = 0; i < k;i++){
        int cur;
        cin >> cur;
        if(cur >= y) best++;
        sum += cur;
    }
    int need = k;
    if(n - k + best < (n + 1)/2){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < (n + 1) / 2 - best;i++){
        sum += y;
        need++;
    }
    sum += n - need;
    if(x < sum){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < (n + 1) /2 - best;i++){
        cout << y << ' ';
    }
    for(int i = 0; i < n - need;i++)
        cout << 1 << ' ';
    return 0;
}