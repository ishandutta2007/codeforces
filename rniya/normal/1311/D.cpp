#include <bits/stdc++.h>
using namespace std;
const int INF=1e9,MAX=3e4+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int a,b,c; cin >> a >> b >> c;
        int ans=INF,A,B,C;
        for (int i=1;i<MAX;++i){
            int cnt=abs(b-i),m=INF,aa,cc;
            for (int j=1;j*j<=i;++j) if (i%j==0){
                if (abs(a-j)<m) m=abs(a-j),aa=j;
                if (abs(a-i/j)<m) m=abs(a-i/j),aa=i/j;
            }
            int k=c/i*i;
            if (!k) cnt+=m+abs(i-c),cc=i;
            else {
                if (abs(k-c)<abs(k+i-c)) cnt+=m+abs(k-c),cc=k;
                else cnt+=m+abs(k+i-c),cc=k+i;
            }
            if (cnt<ans) ans=cnt,A=aa,B=i,C=cc;
        }
        cout << ans << '\n';
        cout << A << ' ' << B << ' ' << C << '\n';
    }
}