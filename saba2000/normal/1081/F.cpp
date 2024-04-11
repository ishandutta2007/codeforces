#include<bits/stdc++.h>
using namespace std;
int ask(int l, int r){
    cout <<"? "<<l<<" "<<r<<endl;
    int x;
    cin >> x;
    if(x == -1) cout<<1/0<<endl;
    return x;
}
int n, t, ct;
int A[3009], P[3009];
void fl(int l, int r){
    for(int i = l; i <= r; i++)
        P[i] = 1 - P[i];
}
void get(int i){
    int l, r;
    if(n % 2 == 0) l = i,r = i;
    else l = i -1, r = i;
    if(i == 1 && n % 2 == 1) l = 2,r = 3;
    while(1){
        int x = ask(l, r);
        if((x - ct -r ) % 2 == 0){
            fl(1, r);
        }
        else fl(l, n);
        ct = x;
        int a = 0, b = 0;
        for(int j = 1; j <= i - 1; j++){
            if(A[j]) a++;
            if(A[j]^P[j]) b++;
        }
        if(i > 1 || n % 2 == 0){
        if( P[i] == 1 && P[i+1] == 0){
            if(t - a > ct - b) {
                A[i] = 1;
            }
            else A[i] = 0;
            return;
        }
        if(P[i] == 0 && P[i+1] == 1){
            if(t - a > (n - i + 1 - ct + b)){
                A[i]  = 1;
            }
            else A[i] = 0;
            return;
        }
        } else{
        if(P[1] == 0 && P[2] == 1){
            //ct-1
            if(ct - 1 == n - 1 - (t -1)) A[1] = 1;
            else A[1] = 0;
            return;
        }

        }
    }
}
main(){
    cin >> n >> t;  ct = t;
    int T = 0;
    if(n == 1){
        cout << "! "<<t<<endl;
        return 0;
    }
    for(int i = 1; i <= n- 1; i++){
        get(i);
        T += A[i];

    }
    if(T == t) A[n] = 0;
    else A[n] =1;
    cout<<"! ";
    for(int i = 1;i <= n; i++)
        cout<<A[i];
    cout<<endl;

}
/*
*/