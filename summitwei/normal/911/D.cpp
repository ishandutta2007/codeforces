#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> ordering;
    ordering.resize(N);
    for(int i=0; i<N; i++){
        cin >> ordering[i];
    }
    bool totalInvs = true;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(ordering[i] > ordering[j]){
                totalInvs = !totalInvs;
            }
        }
    }

    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        
        int diff = abs(a-b)+1;
        int prod = diff*(diff-1)/2;
        if(prod % 2 == 1){
            totalInvs = !totalInvs;
        }

        if(totalInvs == true){
            cout << "even\n";
        } else{
            cout << "odd\n";
        }
    }

    return 0;
}