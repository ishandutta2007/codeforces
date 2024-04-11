#include <bits/stdc++.h>
using namespace std;

const int M = (int)(1e7 + 7e6);

int n;
string s;
int F[M];

int main(){
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        int now = 0;
        for(char c : s) now |= (1 << (c - 'a'));
        F[now]++;
    }
    for(int i = 0; i < 24; i++){
        for(int j = (1 << 24) - 1; j >= 0; j--){
            if(j & (1 << i)) F[j] += F[j - (1 << i)];
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << 24); i++) ans ^= (n - F[i]) * (n - F[i]);
    printf("%d", ans);

}