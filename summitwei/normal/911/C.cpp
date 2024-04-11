#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    vector<int> numbers(3);
    cin >> numbers[0] >> numbers[1] >> numbers[2];

    //cases: all 3, two are 2, 2/4/4
    sort(numbers.begin(), numbers.end());

    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[2];

    if(a == 3 && b == 3 && c == 3){
        cout << "YES";
    } else if(a == 2 && b == 2){
        cout << "YES";
    } else if(a == 2 && b == 4 && c == 4){
        cout << "YES";
    } else if(a == 1){
        cout << "YES";
    } else{
        cout << "NO";
    }

    return 0;
}