#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n=0,i=0,t=0,e=0;
    cin>>s;
    for (int j=0;s[j]!='\0';j++){
        if(s[j]=='n') n++;
        else if(s[j]=='i') i++;
        else if(s[j]=='e') e++;
        else if(s[j]=='t') t++;
    }
    int mi=min(i,min(t,e/3));
    if(n>=(2*mi+1)){
        cout<<mi<<endl;
    }
    else{
        cout<<(n-1)/2<<endl;
    }
}