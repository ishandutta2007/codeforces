#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; string x; cin >> n >> x;
        string a="",b="";
        int equal=1;
        for (int i=0;i<n;++i){
            if (x[i]=='2'){
                if (equal) a+='1',b+='1';
                else a+='0',b+='2';
            }
            if (x[i]=='1'){
                if (equal) a+='1',b+='0',equal=0;
                else a+='0',b+='1';
            }
            if (x[i]=='0') a+='0',b+='0';
        }
        cout << a << '\n' << b << '\n';
    }
}