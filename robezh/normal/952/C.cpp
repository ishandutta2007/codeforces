#include <bits/stdc++.h>
using namespace std;

int num[105];

int diff(int a, int b){
    return a > b ? a - b : b - a;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n-1; i++){
        if(diff(num[i], num[i+1]) >= 2) return !printf("NO");
    }
    return !printf("YES");
}