#include <bits/stdc++.h>
using namespace std;

int n,k,d;
int day[1005][1005];

int main(){
    cin >> n >> k >> d;
    if(k == 1 && n != 1) return !printf("-1");
    if(k <= 1000 && pow(k, d) < 2000 && pow(k, d) < n) return !printf("-1");
    for(int i = 1; i < d; i++) day[0][i] = 1;
    day[0][d] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= d; j++) day[i][j] = day[i-1][j];
        day[i][d] ++;
        for(int j = d; j >= 1; j--){
            if(day[i][j] > k) day[i][j]-=k, day[i][j-1]++;
        }
    }
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= n; j++){
            cout << day[j][i] << " ";
        }
        cout << endl;
    }

}