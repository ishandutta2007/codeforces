#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int count = 0;
    for(int i=1; i<N; i++){
        if((N - i) % i == 0){
            count++;
        }
    }
    cout << count;
    return 0;
}