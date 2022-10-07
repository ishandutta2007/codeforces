#include<bits/stdc++.h>
using namespace std;
int u[300009], f[300009], A[300009],p[300009];
int ans = 0, l=0;
void upd(int x, int v){
    if(v > ans) ans = v, l = x;
}
main(){
    int n,a=0,b=0;
    string s;
    cin >> n>>s;
    for(int i =0; i < n; i++){
        if(s[i] == '(') a++,p[i] = 1;
        else b++,p[i] = -1;
    }
    if(a != b) {cout<<0<<endl<<1<<" "<<1<<endl; return 0;}
    int x= 0, y = 0, st = -1;
    for(int i = 0; i < n; i++){
        x += p[i];
        if(x < y) y = x, st = i;
    }
    st = (st + 1) % n;
    stack<int> S;
    for(int i = st; i < st + n; i++){
        int j = i % n;
        f[j] = x;
        x += p[j];
        if(p[j] == 1) S.push(j);
        else {
            int r = S.top();
            S.pop();
            u[r]  = j;
            u[j] = r;
        }
    }
    for(int i = 0; i < n; i++){
        if(p[i] == -1) continue;
        int x = (i+1)%n;
        while(x != u[i]){
            x = (u[x] + 1)% n;
            A[i]++;
        }
    }
    int t=  0;
    for(int i = 0; i < n; i++){
        if(p[i]==-1) continue;
        if(f[i] == 0) t++;
        if(f[i] == 0) upd(i, A[i]+1);
    }
    for(int i = 0; i < n; i++)
        if(p[i] == 1 && f[i] == 1) upd(i, A[i]+t+1);
   if(t < ans) cout<<ans<<endl<<l+1<<" "<<u[l]+1<<endl;
   else cout<<t<<endl<<1<<" "<<1<<endl;
}
/*

[       ]x
*/