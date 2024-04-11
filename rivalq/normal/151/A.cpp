#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,k,l,c,d,p,nl,np;
   cin>>n>>k>>l>>c>>d>>p>>nl>>np;
   int qeach=k*l/nl;
   int slices = d*c;
   int salteach=p/np;
   vector<int> v={qeach,slices,salteach};
   cout<<*min_element(v.begin(),v.end())/n;


}