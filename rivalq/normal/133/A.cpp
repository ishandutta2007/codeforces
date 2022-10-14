#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
for(int i=0;s[i]!='\0';i++){
    if(s[i]=='H'||s[i]=='Q'||s[i]=='9'){
        cout<<"YES";
        return 0;
    }
}
cout<<"NO";
return 0;

}