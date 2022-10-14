#include<bits/stdc++.h>
using namespace std;
bool check(int num){
    bool visited[10]={false};
    while(num!=0){
        if(visited[num%10]){
           return true; 
        }
        visited[num%10]=true;
        num=num/10;
    }
    return false;

}
int main(){
 
       int y;
       cin>>y;
       int t=y+1;
    while(check(t)){
        t++;
}       
 cout<<t;


}