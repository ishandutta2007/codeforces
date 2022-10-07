#include <bits/stdc++.h> 
using namespace std; 
const int N = 7009;
bitset<N+1> A[100009],B[7009], C[7009],D;
main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j+= i)
            B[j][i] = 1;
    }
    for(int i = N; i >= 1; i--){
        C[i][i] = 1;
        for(int j = 2*i; j <= N; j+= i)
            C[i] ^= C[j];
    }
    string s = "";
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x, v;
            scanf("%d %d", &x, &v);
            A[x] = B[v];
        }
        if(t == 2){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z); 
            A[x] = (A[y]^A[z]);
        }
        if(t == 3){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z); 
            A[x] = (A[y]&A[z]);
        }
        if(t == 4){
            int x, v;
            scanf("%d %d", &x, &v);
            D = (A[x] & C[v]);
            
            if(D.count()&1) s+='1';
            else s +='0';
        }
    }
    cout<<s<<endl;
}
/*
321654

*/