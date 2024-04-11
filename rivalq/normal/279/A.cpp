#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,m;
    cin>>x>>y;
    map<pair<int,int>,int> mp;
    mp.insert({{1,0},1});
    mp.insert({{1,1},1});
    mp.insert({{0,1},2});
    mp.insert({{-1,1},2});
    mp.insert({{-1,0},3});
    mp.insert({{-1,-1},3});
    mp.insert({{0,-1},4});
    mp.insert({{1,-1},4});    
    if((x==0 && y==0) || (x==1 && (y==0))){
        cout<<0<<endl;
    }
    else if(x>0 && y==-(x-1)){
       cout<<4*(x-1)<<endl;
    }
    else {
         m=max(abs(x),abs(y));
         x/=m;
         y/=m;
         auto itr = mp.find({x,y});
         cout<<itr->second + 4*(m-1)<<endl;
    }
   
}