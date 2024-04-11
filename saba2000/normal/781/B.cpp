#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[1009],x[1009],y[1009];int n;
void change(int j){
    s[j] = y[j];
    for(int i =1; i <= n; i++){
        if(i != j && s[i] == s[j] && s[i] != y[i]){
            change(i);
        }
    }
}
main(){
    cin >> n;
    for(int i =1; i <= n; i++){
        string a,b;
        cin>>a>>b;
         x[i] = "",y[i]="";
         x[i]+=a[0]; x[i]+=a[1];
         y[i] = x[i];
         x[i]+=a[2];
         y[i]+=b[0];
    }
    for(int i = 1; i <= n; i++){
        s[i] = x[i];
     }
     for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(j != i && x[j] == x[i]) {
                change(i);
            break;
            }
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++){
        if(s[i] ==s[j]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i =1 ;i <= n; i++)
        cout<<s[i]<<endl;
}