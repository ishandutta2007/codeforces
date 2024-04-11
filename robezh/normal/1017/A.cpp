#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n,a,b,c,d;
int num[N];
int tar;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        num[i] = a + b + c + d;
    }
    tar = num[0];
    sort(num, num+n, greater<int>());
    for(int i = 0; i < n; i++){
        if(tar == num[i]) return !printf("%d", i+1);
    }
}