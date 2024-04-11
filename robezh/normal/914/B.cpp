#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int tmp;
    int cnt[100005];
    fill(cnt, cnt + 100005, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        cnt[tmp] ++;
    }
    for(int i = 1; i <= 100000; i++){
        if(cnt[i] % 2 == 1) return !printf("Conan\n");
    }
    return !printf("Agasa\n");
}