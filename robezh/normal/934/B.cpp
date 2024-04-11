#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    if(k >= 37) return !printf("-1");
    for(int i = 0; i < k/2; i++) printf("8");
    if(k % 2 == 1) printf("9");
}