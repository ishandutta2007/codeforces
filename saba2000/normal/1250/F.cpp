#include<bits/stdc++.h>
using namespace std;
main(){
    long long men;
    cin >> men;
    long long k = 0, x= 1;
    for(long long i = 2; i * i <= men; i++){
        if(men % i == 0) {
            k++;
            x = i;
            while(men % i == 0)
                men /= i;
        }
    }
    if(men > 1) k ++, x = men;
    if(k > 1) {
        cout<<1<<endl;
        return 0;
    }
    cout<<x<<endl;
}
//1=3=5=2