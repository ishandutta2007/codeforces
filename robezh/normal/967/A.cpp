#include <bits/stdc++.h>
using namespace std;

int n,s,a,b;
int num[105];

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        num[i] = a * 60 + b;
    }
    if(num[0]-1 >= s) return !printf("0 0");
    for(int i = 0; i < n-1; i++){
        if(num[i+1] - num[i] >= 2 * s + 2){
            int res = num[i] + 1 + s;
            return !printf("%d %d\n", res/60, res%60);
        }
    }
    int res = num[n-1] + 1 + s;
    return !printf("%d %d", res / 60, res % 60);

}