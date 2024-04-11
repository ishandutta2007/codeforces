#include <bits/stdc++.h>
using namespace std;

int n;
int num[200050];
string ok;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    getchar();
    getline(cin, ok);

    int nummax = 0;
    for(int i = 1; i <= n-1; i++){
        nummax = max(nummax, num[i]);
        if(ok[i-1] == '0'){
            if(nummax != i) return !printf("NO");
        }
    }
    return !printf("YES");
}