#include <bits/stdc++.h>
using namespace std;

int n;
int num[200050];
int d[200050];
int ooo = 1000000000;

int dif(int a, int b){
    return (a > b ? a - b : b - a);
}
int res = -1;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = 1; i < n; i++){
        int di = dif(num[i],num[i-1]);
        if(di == 0) return !printf("NO");
        d[i] = di;
        if(di != 1){
            if(res == -1) res = di;
            else if(res != di) return !printf("NO");
        }
    }
    if(res != -1){
        for(int i = 1; i < n; i++){
            if(d[i] == 1){
                //cout << res;
                if(min(num[i-1], num[i]) % res == 0) return !printf("NO");
            }
        }
        printf("YES\n");
        cout << ooo << " " << res;
    }
    else{
        printf("YES\n");
        cout << ooo << " " << ooo << endl;
    }

}