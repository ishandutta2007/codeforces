#include<iostream>
using namespace std;
int main(){
    long long N,M,K;
    cin>>N>>M>>K;
    cout<<((N+K-1)/K)*((M+K-1)/K)<<endl;
}