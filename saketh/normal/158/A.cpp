#include<iostream>
using namespace std;

int N, K, A;
int s[55];

int main(){
    cin >> N >> K;
    for(int n=0; n<N; n++)
        cin >> s[n];
    int c = s[K-1];
    for(int n=0; n<N; n++)
        if(s[n]>=c && s[n]>0)
            A++;
    cout << A << endl;
}