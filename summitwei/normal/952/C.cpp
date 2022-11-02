#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007

int main(){
    int N;
    cin >> N;

    vi amts(N);
    for(int i=0; i<N; i++){
        cin >> amts[i];
    }

    for(int i=1; i<N; i++){
        if(abs(amts[i] - amts[i-1]) > 1){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}