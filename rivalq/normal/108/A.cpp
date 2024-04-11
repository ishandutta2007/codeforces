#include<bits/stdc++.h>
using namespace std;
int ip(string s,int l){
   int i=0,j=l-1;
   while(i<=j){
       if(s[i]!=s[j]) return 0;
       i++;j--;
   }
   return 1;
}
int main(){
    string s;
   cin>>s;
   int h = stoi(s.substr(0,2));
   int m = stoi(s.substr(3,2));
   s="";
   m=(++m)%60;
   if(m==0){
        h=(++h)%24;
    }
      if(h/10==0) s="0" + to_string(h)+":";
      else s= to_string(h) + ":";
      if(m/10==0) s+="0"+to_string(m);
      else s+=to_string(m);
    while(!ip(s,5)){
        m=(++m)%60;
        if(m==0) {
        h=(++h)%24;
    }
      if(h/10==0) s="0" + to_string(h)+":";
      else s= to_string(h) + ":";
      if(m/10==0) s+="0"+to_string(m);
      else s+=to_string(m);
    }
    cout<<s<<endl;
    

}