#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105, INF = (int)1e9;
const int M = (int)2e5 + 50;

int n, t;
int s[N], d[N];
int arr[M];

int main() {
    cin >> n >> t;
    fill(arr, arr + M, -1);
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> d[i];
        for(int k = s[i]; k < M; k += d[i]) arr[k] = i;
    }
    for(int i = t; i < M; i++) {
        if(arr[i] != -1) return !printf("%d\n", arr[i] + 1);
    }


}