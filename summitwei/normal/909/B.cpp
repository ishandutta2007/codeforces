#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int A;
    cin >> A;

    if(A % 2 == 0){
        cout << (A/2)*(A/2+1);
    } else{
        cout << (A+1)*(A+1)/4;
    }

    return 0;
}