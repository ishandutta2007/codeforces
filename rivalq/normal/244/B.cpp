#include<bits/stdc++.h>
using namespace std;
int n;
int k=0;
int check(long long num){
    set<int> se;

    while(num!=0){
        se.insert(num%10);
        num/=10;
    }
    return se.size()<=2;
}
set<long long> s;
void tree(long long num){
   if(num>n) return ;
   else{
      s.insert(num);
   }
   for(int i=0;i<10;i++){
      int num1=num*10+i;
       if(num1 && check(num1)) tree(num1);
   }

   
}
int main(){
    cin>>n;
    tree(0);
    //tree(0,4,7);
    //for(auto i:s)cout<<i<<" ";
    //cout<<endl;
    cout<<s.size()-1<<endl;
}