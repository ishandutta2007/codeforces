#include<bits/stdc++.h>

using namespace std;
using nagai=long long;

nagai f(nagai x){
x++;
while(x%10==0)x/=10;
return x;
}

int main(){
 nagai n;
 cin>>n;
 set<nagai>s;
 for(int i=0;i<1000;++i)
	 s.insert(n),n=f(n);
 cout<<s.size()<<'\n';
}