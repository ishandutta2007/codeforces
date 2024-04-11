#include<bits/stdc++.h>
using namespace std;
int a[300009];
int M[300009];
int F[300009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = n - a[i];
        M[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(M[i] % i != 0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(M[a[i]] % a[i] == 0){
            F[a[i]] = cnt;
            cnt++;
        }
        M[a[i]]--;
        cout<<F[a[i]]<<" ";
    }

}