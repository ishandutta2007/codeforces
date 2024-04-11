#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    string A, B;
    cin >> A >> B;

    string answer = "";
    
    answer += A[0];
    for(int i=1; i<A.length(); i++){
        if(A[i] < B[0]){
            answer += A[i];
        } else{
            break;
        }
    }

    cout << answer << B[0];

    return 0;
}