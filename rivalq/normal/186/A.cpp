#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.length();
    int n2 =s2.length();
    if(n1==n2){
        int c=0;
      int arr[2];
        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]) {
             if(c<2) arr[c]=i;
             c++;
             }
        }
        if(c==2 && s1[arr[0]]==s2[arr[1]] && s1[arr[1]]==s2[arr[0]]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}