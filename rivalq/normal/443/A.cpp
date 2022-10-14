#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  vector<char> c;
  getline(cin,s);
  int i=1;
  int n=s.length()-1;
   while(i<n)
   {
    c.push_back(s[i]);
    i=i+3;
   }
   bool visit[26]={false};
   int count=0;
    n=c.size();
   for(int i=0;i<n;i++){
       if(!(visit[c[i]-97])){
        visit[c[i]-97]=true;
        count++;
       }
   }

cout<<count<<endl;
}

//{a, b, c}
//012345678