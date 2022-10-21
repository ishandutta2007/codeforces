#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        string S; cin >> S;
        int N=S.size(),lb=0,ub=N+2;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            int now=0;
            while(now<N+1){
                int ok=0;
                for (int i=min(now+mid,N+1);i>now;--i){
                    if (i==N+1||S[i-1]=='R'){now=i; ok=1; break;}
                }
                if (!ok) break;
            }
            (now==N+1?ub:lb)=mid;
        }
        cout << ub << '\n';
    }
}