#include<iostream>
 
using namespace std;
 
int main(){
    int n , m , aray[50] , min = 50000000;
    cin>>m>>n>>aray[0];
    for(int i = 1 ; i < n ; i++){
        cin>>aray[i];
        for(int j = i - 1 ; j > -1 ; j--){
            if(aray[j] > aray[j+1]){
                swap(aray[j],aray[j+1]);
            }
            else{
                break;
            }
        }
    }
    for(int i = 0 ; i < n-m+1 ; i++){
        if(aray[i+m-1] - aray[i] < min){
            min = aray[i+m-1] - aray[i];
        }
    }
    cout<<min<<endl;
    return 0;
}