#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 16;

int n;
int a[N];

bool check(int i, int now){
    if(i == n) return now % 360 == 0;
    return check(i + 1, now + a[i]) || check(i + 1, now - a[i]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(check(0, 0)) printf("YES");
    else printf("NO");
}