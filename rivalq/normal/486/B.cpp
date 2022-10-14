//https://codeforces.com/problemset/problem/486/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n,a) for(int i=0;i<n;i+=a)
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int b[n][m],a[n][m];
    lop(i,n,1) lop(j,m,1) a[i][j]=1;
    lop(i,n,1) lop(j,m,1) cin>>b[i][j];
    lop(i,n,1){
        lop(j,m,1){
            if(b[i][j]==0){
                lop(k,n,1) a[k][j]=0;
                lop(k,m,1) a[i][k]=0;
            }
        }
    }
    lop(i,n,1){
        lop(j,m,1){
            if(b[i][j]==1){
                int c=0;
                lop(k,n,1){
                   if(a[k][j]) {c=1;goto j;}
                }
                lop(k,m,1){if(a[i][k]){c=1;break;}}
                j:
                if(c==0) {cout<<"NO\n";return 0;} 
            }
        }
    }
    cout<<"YES\n";
    lop(i,n,1){
        lop(j,m,1){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}