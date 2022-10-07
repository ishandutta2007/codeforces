#include<bits/stdc++.h>
using namespace std;
int x[4],y[4],X[4],Y[4];
main(){
    int x1 = 1000, x2=-1000, y1=1000, y2= -1000;
    for(int i = 0; i < 4; i++){
        cin >> x[i]>>y[i];
        x1 =min(x1, x[i]);
        y1 = min(y1, y[i]);
        x2 = max(x2, x[i]);
        y2 = max(y2, y[i]);
        int a= x[i], b = y[i];
        x[i] = (a+b);
        y[i] = (b-a);
    }
    int X1 = 1000, X2=-1000, Y1=1000, Y2= -1000;
    for(int i = 0 ;i < 4; i++){
        cin >> X[i] >>Y[i];
        int a=X[i],b=Y[i];
        X[i] =a+b;
        Y[i] =b-a;
        X1 =min(X1, X[i]);
        Y1 = min(Y1, Y[i]);
        X2 = max(X2, X[i]);
        Y2 = max(Y2, Y[i]);
    }
    for(int i = -100; i <= 100; i++){
        for(int  j = -100; j <= 100; j++){
            int a = i+j, b = j -i ;
            if(i >= x1 && i <= x2 && j >= y1 && j <= y2 && a >= X1 && a <= X2 && b >= Y1 && b <= Y2){
                cout<<"yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"no"<<endl;

}