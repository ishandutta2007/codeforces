#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<35;i++){
        if(i*(i+1)==n*2){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}