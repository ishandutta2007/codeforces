#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int dif[6];
    int x = 0;
    int ans = 0;
    int N[6];
    for(int i = 0; i < 6; i++){
        N[i] = s[i] - '0';
    }
    if(N[0] + N[1] + N[2] > N[3] + N[4] + N[5]){
        for(int i = 0; i < 3; i++){
            dif[i] = N[i];
        }
        for(int i = 0; i < 3; i++){
            dif[i+3] = 9-N[i+3];
        }
        sort(dif, dif+6);
        while(ans < N[0] + N[1] + N[2] - N[3] - N[4] - N[5]){
            ans += dif[5-x];
            x++;
            
        }
    }
    else if(N[0] + N[1] + N[2] < N[3] + N[4] + N[5]){
        for(int i = 0; i < 3; i++){
            dif[i] = 9-N[i];
        }
        for(int i = 0; i < 3; i++){
            dif[i+3] = N[i+3];
            
        }
        sort(dif, dif+6);
        while(ans < N[3] + N[4] + N[5]-N[0] - N[1] - N[2]){
            ans += dif[5-x];
            x++;
        }
    }
    cout << x;
}