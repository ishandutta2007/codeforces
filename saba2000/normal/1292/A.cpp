#include<bits/stdc++.h>
using namespace std;
int a[100009][2],f[100009];
int ans  =0 ;
int n,q;
void upd(int c){
    if(c <= 0 || c >= n) return;
    ans -= f[c];
    f[c] = 1;
    if(!a[c][0] && !a[c+1][0]) f[c] = 0;
    if(!a[c][1] && !a[c+1][1]) f[c] = 0;
    ans+=f[c];
}
main(){
    cin >> n >> q;
    for(int i =1; i <= q; i++){
        int r,c;
        cin>>r>>c;
        r--;
        a[c][r] ^=1;
        upd(c);
        upd(c-1);
        upd(c+1);
        if(ans) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}