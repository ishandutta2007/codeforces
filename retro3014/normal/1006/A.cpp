#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main(){
    cin>>N;
    while(N--){
        cin>>M;
        if(M%2){
            cout<<M<<" ";
        }
        else{
            cout<<M-1<<" ";
        }
    }
    return 0;
}