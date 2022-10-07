#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = "", b = "";
    int ok = 1;
    int A = 0, B = 0;
    int k = 0,k1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') k++;
    }
    if(k % 2 || n % 2){
        cout <<"NO"<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && k1 < k/2){
            A++;
            B++;
            a += '(';
            b += '(';
            k1++;
        } else
        if(s[i] == '1'){
            A--;
            B--;
            a += ')';
            b += ')';
            k1++;

        }
        if(s[i] == '0'){
            if(A > B){
                A--;
                B++;
                a += ')';
                b += '(';
            }
            else{
                B--;
                A++;
                b += ')';
                a += '(';
            }
        }
        if(A < 0 || B < 0 ) {
        cout << "NO"<<endl;
        return;
        }
    }
    if(A) {
        cout << "NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl<<a<<endl<<b<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}