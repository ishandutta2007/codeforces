#include<bits/stdc++.h>
using namespace std;
int A[500009],B[500009];
main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int a = 0, m = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') a++;
            else a--;
            m = min(m, a);
        }
        if((a >= 0 && m == 0) || a == m) {
            if(a >= 0) A[a]++;
            else B[-a]++;
        }
    }
    int ans = 0 ;
    for(int i = 1;i <= 500009; i++)
        ans += min(A[i], B[i]);
    cout << ans + A[0]/2<< endl;
    
}