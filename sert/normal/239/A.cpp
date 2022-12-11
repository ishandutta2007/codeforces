#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

#define fr(i, n) for(int i = 0; i < n; i++)
#define fab(i, a, b) for(int i = a; i <= b; i++)

typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int k;
    int y;

    cin >> y >> k >> n;
    //cout << y << n << k;
    
    int h = (y + k) / k;
    int hk = n / k;
    //cout << " 3 " << h << " " << hk << "\n"; 
    if (h > hk) cout << "-1";
    fab(i, h, hk) cout << i * k - y << " ";

    return 0;
}