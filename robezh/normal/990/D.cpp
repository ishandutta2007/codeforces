#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int mat[1005][1005];

void print(){
    printf("YES\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    cin >> n >> a >> b;
    if(a != 1 && b != 1) return !printf("NO");
    if(a == 1 && b == 1){
        if(n == 2 || n == 3) return !printf("NO");
        for(int i = 0; i < n-1; i++){
            mat[i][i+1] = 1;
            mat[i+1][i] = 1;
        }
        print();
        return 0;
    }
    int num = (a == 1 ? b : a);
    for(int j = 1; j < n - num + 1; j++) mat[0][j] = mat[j][0] = 1;
    if(a == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j) mat[i][j] = 1 - mat[i][j];
            }
        }
    }
    print();

}