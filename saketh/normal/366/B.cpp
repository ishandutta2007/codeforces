#include<iostream>
using namespace std;

int N, K, tmp;
int bucket[100005];

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> tmp;
        bucket[i % K] += tmp;
    }

    int midx = 0;
    for(int i=0; i<K; i++)
        if(bucket[i] < bucket[midx])
            midx = i;
    cout << midx+1 << endl;
    return 0;
}