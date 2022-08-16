#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int iter;
    cin>>iter;
    for(long long t=0; t<iter; t++){
        int n;
        long long sum, minval;
        cin>>n;
        sum = 0;
        long long zer = 0;
        
        long long begin;
        long long i1, i2,prev;
        for(int k=0; k<n; k++){
            cin>>i1>>i2;
            if(k==0){
                begin = i1;
                minval = i1;
            }
            else{
                sum+=max(zer,i1-prev);
                minval = min(minval,i1-(max(zer,i1-prev)));
            }
            
            prev = i2;
        }
        sum+=max(zer,begin-i2);
        minval = min(minval,begin-(max(zer,begin-i2)));
        cout<<sum+minval<<"\n";
    }
 
 
    return 0;
}