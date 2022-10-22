#include<bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    while(Q--){
        int N;
        cin>>N;
        for(int i=1;i<=N;i++){
            cout<<i;
            if(i==N)cout<<endl;
            else cout<<' ';
        }
    }
}