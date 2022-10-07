#include<bits/stdc++.h>
using namespace std;
int p[10000009];
int A[500009],B[500009];
int M = 10000000;
main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i =2; i <= M; i++){
        if(p[i]) continue;
        for(int j = i; j <= M; j += i)
            p[j] = i;

    }
    for(int i =1; i <= n; i++){
        int a;
        cin >> a;
        int x = p[a], y = a;
        while(y % x == 0) y /= x;
        if(y == 1){
            A[i] = -1; B[i] = -1;
        }
        else {
            A[i] = y, B[i] = a / y;
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<A[i]<<" ";
        cout<<endl;
    for(int i =1 ; i <= n; i++)
    cout<<B[i]<<" ";
}
/*



*/