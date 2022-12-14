//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    long long sum = 0;
    long long one = 0;
    long long n;
    long long k;
    cin >> n >> k;
    long long m = n;
    int N = 0;
    for(long long i = 0; i < m;i++){
        int Nnow;
        scanf("%d",&Nnow);
        long long now = Nnow;
        long long ver = sum - ((i-N) * ((n-N) - (i-N) - 1) * now);
        if(ver < k){
            cout << i+1 << "\n";
            N++;
        }else{
            sum += (i-N) * now;
        }
    }
    return 0;
}