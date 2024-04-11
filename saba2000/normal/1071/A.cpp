#include<bits/stdc++.h>
using namespace std;
main(){
    long long a, b;
    cin >> a >> b;
    long long i;
    for(i = 0; i <= 3e5; i++){
        if((i+2)*(i+1)/2 > a+b) break;
    }
    vector<int> A, B;
    long long M = max(0ll,i*(i+1)/2 - b);
    for(long long x = i; x >= 1; x--){
        if(x <= M) {
            M -= x;
            A.push_back(x);

        }
        else B.push_back(x);
    }
    cout << A.size()<<endl;
    for(int i = 0; i < A.size(); i++)
        printf("%d ", A[i]);
    cout<<endl;
    cout << B.size()<<endl;
    for(int i = 0; i < B.size(); i++)
        printf("%d ", B[i]);
    cout<<endl;

}