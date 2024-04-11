#include<bits/stdc++.h>
using namespace std;
int a[100009];
int s[100009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int l = -1,r;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] % x != 0){ if(l == -1) l = i;
                r = i;
            }
            s[i] = s[i-1] + a[i];
        }
        if(l == -1){cout<<-1<<endl; continue;}
        if(s[n] % x != 0) cout << n<<endl;
        else cout << max(r-1, n - l)<<endl;
    }

}