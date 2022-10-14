#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   map<int,int> m;
   map<int,int>::iterator itr;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       m.insert({t,i+1});
   }
   for (itr = m.begin(); itr != m.end(); ++itr) { 
        cout<< itr->second<<" ";
    } 
    cout << endl;




}