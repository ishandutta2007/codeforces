#include<bits/stdc++.h>
using namespace std;
int P[5009][5009];
int f[5009];
main(){
    string s;
    cin >> s;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j + i -1 < s.size(); j++){
            int k = j+i-1;
            if(s[j] == s[k] && (i <= 2 || P[j+1][k-1])){
               if(i <= 1) P[j][k]  =1;
                else P[j][k] = min(P[j][j+i/2-1], P[k-i/2+1][k]) + 1;
                f[P[j][k]] ++;
            }
        }
    }
    for(int i = s.size(); i >= 1; i--)
        f[i]+=f[i+1];
    for(int i = 1; i <= s.size(); i++)
        cout<<f[i]<<" ";
    cout<<endl;
}