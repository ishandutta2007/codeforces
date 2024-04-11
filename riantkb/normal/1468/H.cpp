#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,k,m;
        cin >> n >> k >> m;
        vector<int> a(m+2);
        a[0] = 0;
        a[m+1] = n+1;
        rep(i,m){
            cin >> a[i+1];
        }
        vector<int> b;
        rep(i,m+1){
            b.push_back(a[i+1]-a[i]-1);
        }
        vector<int> sm(m+1);
        rep(i,m+1){
            sm[i] += b[i];
            if(i!=0)sm[i] += sm[i-1];
        }
        if(sm[m]%(k-1)!=0){
            cout << "NO\n";
            continue;
        }
        bool flag = 0;
        rep(i,m+1){
            int L,R;
            L = sm[i];
            R = sm[m]-sm[i];
            if(L>=k/2 && R>=k/2){
                flag = 1;
            }
        }
        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}