#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int num[200050];
    long long sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        sum += num[i];
    }
    long long now = 0;
    for(int i = 1; i <= n; i++){
        now += num[i];
        if(now * 2 >= sum) return !printf("%d", i);
    }
}