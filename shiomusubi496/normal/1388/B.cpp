#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    while(N--){
        long long A;
        cin>>A;
        long long B=(A+3)/4;
        for(long long i=0;i<A-B;i++)cout<<9;
        for(long long i=0;i<B;i++)cout<<8;
        cout<<endl;
    }
}