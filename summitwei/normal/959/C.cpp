#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007

int main(){
    int n;
    cin >> n;

    if(n <= 5){
        cout << "-1\n";
    } else{
        cout << "1 2\n1 3\n1 4\n";
        for(int i=5; i<=n; i++){
            cout << "2 " << i << "\n";
        }
    }

    for(int i=1; i<n; i++){
        cout << i << " " << i+1 << "\n";
    }

    return 0;
}