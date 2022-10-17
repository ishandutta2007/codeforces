#include<iostream>
using namespace std;

long long N, I;
long long D, A = 0;
long long v[100005];

int main(){
    cin >> N >> D;
    for(int n=0; n<N; n++){
        cin >> v[n];
        while(v[n]-v[I] > D)
            I++;
        if(n>I)
            A += ((n-I)*(n-I-1))/2;
    }
    cout << A << endl;
}