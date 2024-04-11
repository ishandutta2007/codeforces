#include<bits/stdc++.h>
using namespace std;
int a[100009];
map<int,int> M;
main(){
    int n, l, x,y;
    cin>> n>> l >> x >>y;
    for(int i =1; i <= n; i++){
        cin >> a[i];
        M[a[i]]= 1;
    }
    int okx = 0, oky = 0, okxy = 0, ok2 = 0, ok3 = 0;
    for(int i =1; i <= n; i++){
        if(M[a[i]+x]) okx = 1;
        if(M[a[i] + y]) oky = 1;
        if(M[a[i] + x  +y]) okxy = a[i]+1;
        if(M[a[i] + x - y] && !ok2) ok2 = a[i]+1;
        if(M[a[i] + x - y]  ) ok3 = a[i]+1;
    }
    if(okx + oky  == 2) cout<<0<<endl;
    else if(!okx && oky) cout <<1<<endl<<a[1]+x<<endl;
    else if(!oky && okx) cout <<1<<endl<<a[1]+y<<endl;
    else if(okxy) cout<<1<<endl<<okxy+x-1<<endl;
    else if(ok2 && ok2+x-1<=l && ok2+x-1>=0) cout<<1<<endl<<ok2 +x-1<<endl;
    else if(ok3 && ok3-y-1<=l && ok3-y-1>=0) cout<<1<<endl<<ok3 -y-1<<endl;
    else cout<<2<<endl<<a[1]+x<<" "<<a[1]+y<<endl;
    
}