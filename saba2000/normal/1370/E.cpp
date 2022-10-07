#include<bits/stdc++.h>
#define ll long long
using namespace std;
int A[1000009],B[1000009];
main(){
    int n;
    cin >> n;
    string a,b;
    cin>>a>>b;
    for(int i = 0; i < n; i++)
        A[i+1] = (a[i] == '1'),
        B[i+1] = (b[i] == '1');
    int cant = 0;
    for(int i =1 ; i <= n; i++){
        cant += A[i] - B[i];
    }
    if(cant){
        cout<<-1<<endl;
        return 0;
    }

    int o = 0, z = 0;
    for(int i = 1; i <= n; i++)
        if(A[i] != B[i]) {
            if(A[i] == 0) o--, z++;
            else z--, o++;
            if(o < 0) o = 0;
            if(z < 0) z = 0;
        }
    cout<<o+z<<endl;
}