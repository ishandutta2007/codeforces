#include<bits/stdc++.h>
using namespace std;
int f[1009];
main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
            f[s[i]]++;
    }
    int y = 0, x = 0;
    for(int i = 'a'; i <= 'z'; i++){
        if(f[i] == 1) x++;
        if(f[i] > 1) y++;
    }
    if(y == 0 && x > 1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;


}