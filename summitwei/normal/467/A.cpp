#include <bits/stdc++.h>
using namespace std;

int main(){int N;cin >> N;int count = 0;for(int i=0; i<N; i++){int a, b;cin >> a >> b;if(b-a > 1){count++;}}cout << count;return 0;}